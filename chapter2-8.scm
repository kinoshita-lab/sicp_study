(require racket/trace)
(load "./chapter2_utility.scm")
(load "./code_from_text/ch2support.scm")
(load "./chapter2_install-packages.scm")
;;;
;;; 2.5.2 異る型のデータの統合
;;;
(define (scheme-number->complex n)
  (make-complex-from-real-imag (contents n) 0))

;; ここでput/get coercionとかいうのが必要になっている気がする
(define coercion-list '())

(define (clear-coercion-list)
  (set! coercion-list '()))

(define (put-coercion type1 type2 item)
  (if (get-coercion type1 type2) coercion-list 
      (set! coercion-list
            (cons (list type1 type2 item)
                  coercion-list))))

(define (get-coercion type1 type2) 
  (define (get-type1 listItem)
    (car listItem))
  (define (get-type2 listItem)
    (cadr listItem))
  (define (get-item listItem)
    (caddr listItem))
  (define (get-coercion-iter list type1 type2)
    (if (null? list) #f
        (let ((top (car list)))
          (if (and (equal? type1 (get-type1 top))
                   (equal? type2 (get-type2 top))) (get-item top)
                   (get-coercion-iter (cdr list) type1 type2)))))
  (get-coercion-iter coercion-list type1 type2))

;; apply-genericを書き換える
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (let ((t1->t2 (get-coercion type1 type2))
                      (t2->t1 (get-coercion type2 type1)))
                  (cond (t1->t2
                         (apply-generic op (t1->t2 a1) a2))
                        (t2->t1
                         (apply-generic op a1 (t2->t1 a2)))
                        (else
                         (error "No method for these types"
                                (list op type-tags))))))
              (error "No method for these types"
                     (list op type-tags)))))))
                    
;; 試し
(clear-putlist)
(install-scheme-number-package)
(install-complex-package)
(install-rectangular-package)
(put-coercion 'scheme-number 'complex scheme-number->complex)
(define a (make-scheme-number 10))
(define b (make-complex-from-real-imag 1 2))
(trace apply-generic)
(trace get)
(add a b)
;; あまりにも動かなくてやる気が失せてきたが問題はといてみる(うごかないけど)
;; 問題 2.81

;; Louis Reasonerは, apply-genericは引数が既に同じ型を持っていても, 互いの型へ強制変換を試みるべきだと考えた. そこで彼が考えるには, 上に示した強制型変換の表に, 各型の引数を自分の型へ「強制変換」させる手続きを置く必要がある. 例えば上に示したscheme-number->complex型変換に加え, 彼は

;; (define (scheme-number->scheme-number n) n)

;; (define (complex->complex z) z)
;; (put-coercion 'scheme-number 'scheme-number
;;               scheme-number->scheme-number)
;; (put-coercion 'complex 'complex complex->complex)
;; としようとする. 

;; a. Louisの強制型変換手続きが設定されると, apply-genericが型scheme-numberの二つの引数や型complexの二つの引数で, これらの型で表に見つからない手続きに対して呼び出されると, 
;; 何が起きるか. 例えば汎用べき乗演算:
;; (define (exp x y) (apply-generic 'exp x y))
;; が定義してあり, scheme数パッケージのべき乗の手続き
;;  ;; 次はScheme数パッケージへ追加する
;; (put 'exp '(scheme-number scheme-number)
;;      (lambda (x y) (tag (expt x y))))  ; 基本手続きexptを使う.
;; はあるが, 他のパッケージにはないとしよう. 引数に二つの複素数を持ってexpを呼び出すと何が起きるか. 

;; 実際に計算するには 43行目のgetで有効な演算が呼び出されないとだめ。
;; なかった場合、型の変換をしたうえで再度apply-genricを呼び出す。↑のようにgetで適切な演算が呼び出せない場合、
;; 例えば complex->complexの計算は定義してあるため、無限にapply-genericを呼び出すことになってしまう。

;; b. 同じ型の引数の強制型変換について何かすべきだというLouisは正しいか. それともこのままapply-genericは正しく働くか. 
;; Louisは正しくないと思う。同じ型の強制変換が呼ばれるように鳴っている場合　53行目のcondで必ず上のt1->t2が存在してしまう。

;; c. 二つの引数が同じ型を持っていれば, 強制型変換を試みないように, apply-genericを修正せよ. 
;; こんなかな(動かしてないけど)
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (let ((t1->t2 (get-coercion type1 type2))
                      (t2->t1 (get-coercion type2 type1)))
                  (if (equal? type1 type2) ; ここ足した
                      (apply-generic op a1 a2) ; ここ足した
                      (cond (t1->t2
                             (apply-generic op (t1->t2 a1) a2))
                            (t2->t1
                             (apply-generic op a1 (t2->t1 a2)))
                            (else
                             (error "No method for these types"
                                    (list op type-tags))))))))
          (error "No method for these types"
                 (list op type-tags))))))

;; 問題 2.82

;; 多くの引数を持つ一般の場合に, 強制型変換が使えるよう, apply-genericをどう一般化すればよいか示せ. 一つの戦略はすべての引数を第一引数の型, 次に第二引数の型等々に強制変換を試みることである. この戦略が(そして上の二引数版が)十分に一般的でない状況の例をあげよ. (ヒント: 表の中に試みられない何か適当な混合型の演算がある場合を考えよ.) 
;; 一般的にはより多くの情報を持っている型に変換すればよいと思う。
;; いまここまでで定義されているシステム（？）の場合だと、scheme-numberは有理数と複素数に型の塔を登れるけど、有理数と複素数の演算は定義できていない。
;; 同じようなことが型の数を増やしていくと増えるような気がする。有理数と実数でも 1/3を0.333にしたらもう元に戻せないし。
;; テキストに出てくる「型の塔」という図はザックリあってそうだけどよく考えるとそう直線で結べるものには少なくとも現状なっていない。

;; 問題 2.83

;; 図2.25に示した型の塔: 整数, 有理数, 実数, 複素数を扱う汎用算術演算システムを設計しているとしよう. (複素数を除く)各型について, その型のオブジェクトを塔の中で一レベル高める手続きを設計せよ. (複素数を除く)各型に働く汎用raise演算はどう設計するか. 
;; install-xx-packageごとに作るべきなのかと思ったけど、そうするとお互いを知っている状況みたいなことになるので、raiseだけやる用の手続きを定義したほうが良さそう。
;; 多分こんな感じ
(define (raise x)
  (let ((type (type-tag x)))
    (cond 
     ((equal? type 'scheme-number) (make-rational contents x 0))
     ((equal? type 'rational) (make-real ; もうここから作ってないし
                               (inexact (/ (car (contents x)) (cadr (contents x))))))
     ((equal? type 'real) (make-complex-from-real-imag (contents x) 0.0)))))

;; 問題 2.84
;; 問題2.83のraise演算を使ってapply-generic手続きを修正し, 本節で論じたように順次に高めていく方法で, 引数を同じ型になるまで, 強制変換するようにせよ. 二つの型のいずれが塔の中で高いかをテストする方法を考えなければならない. これをシステムの他の部分と「整合している」方法で行い, 塔に新レベルを追加する時の問題を生じないようにせよ. 
;; 2.81ベースで(例によって動かしていない)

;; 飛ばした

;; 問題 2.85

;; 本節ではデータオブジェクトを, 型の塔を出来るだけ下げ, 「単純化」する方法を述べた. 問題2.83で述べた塔についてこれを実施する手続きdropを設計せよ. 鍵は何か一般的方法でオブジェクトを下げられるか決めることである. 例えば複素数1.5 + 0iはrealまで下げられ, 複素数1 + 0iはintegerまで下られるが, 複素数2 + 3iは全く下げられない. オブジェクトが下げられるかを決める方法がある: オブジェクトを塔に沿って下へ「押す」汎用演算projectの定義から始める. 例えば複素数の投影は虚部を捨てることである. 数をprojectし, 結果をraiseして出発した型に戻した時, 出発したのと同じ何かで終れば, 数は切り下げられる. オブジェクトを出来るだけ下げるdrop手続きを書いて, この考えを実装する方法を詳しく述べよ. いろいろな投影演算53 を設計し, project をシステムに汎用に実装する必要がある. また問題2.79で述べた汎用等価述語を利用する必要がある. 最後に答を「単純化する」ように問題2.84のapply-genericを書き直すのにdropを使え. 


;; 飛ばした

;; 問題 2.86
;; 複素数で実部, 虚部, 絶対値および偏角が通常の数, 有理数またはシステムに追加しようと思うかも知れぬ他の数であるものを扱いたいとしよう. これを取り込むのに必要なシステムの変更を記述し, 実装せよ. 通常の数と有理数に汎用なsineやcosineのような演算も定義しなければならない. 

;; 飛ばした

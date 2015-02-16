; 2.4.1 複素数の表現
(use slib)
(require 'trace)
; true/falseない
(define false #f)
(define true #t)


(define (add-complex z1 z2)
  (make-from-real-imag (+ (real-part z1) (real-part z2))
                       (+ (imag-part z1) (imag-part z2))))

(define (sub-complex z1 z2)
  (make-from-real-imag (- (real-part z1) (real-part z2))
                       (- (imag-part z1) (imag-part z2))))


(define (mul-complex z1 z2)
  (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                     (+ (angle z1) (angle z2))))

(define (div-complex z1 z2)
  (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                     (- (angle z1) (angle z2))))


;; benの
(define (real-part z) (car z))
(define (imag-part z) (cdr z))

(define (magnitude z)
  (sqrt (+ (square (real-part z)) (square (imag-part z)))))

(define (angle z)
  (atan (imag-part z) (real-part z)))

(define (make-from-real-imag x y) (cons x y))

(define (make-from-mag-ang r a)
  (cons (* r (cos a)) (* r (sin a))))

;; alyssaの
(define (real-part z)
  (* (magnitude z) (cos (angle z))))

(define (imag-part z)
  (* (magnitude z) (sin (angle z))))

(define (magnitude z) (car z))

(define (angle z) (cdr z))

(define (make-from-real-imag x y)
  (cons (sqrt (+ (square x) (square y)))
        (atan y x)))

(define (make-from-mag-ang r a) (cons r a))


; 2.4.2 タグ付きデータ

(define (attach-tag type-tag contents)
  (cons type-tag contents))


(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (error "Bad tagged datum -- TYPE-TAG" datum))); なぜ急にエラーチェック？

(define (contents datum)
  (if (pair? datum)
      (cdr datum)
      (error "Bad tagged datum -- CONTENTS" datum)))

(define (rectangular? z)
  (eq? (type-tag z) 'rectangular))

(define (polar? z)
  (eq? (type-tag z) 'polar))


;; benの
(define (real-part-rectangular z) (car z))
(define (imag-part-rectangular z) (cdr z))

(define (magnitude-rectanguler z)
  (sqrt (+ (square (real-part-rectangular z))
           (square (imag-part-rectangular z)))))

(define (angle-rectangular z)
  (atan (imag-part-rectangular z)
        (real-part-rectangular z)))

(define (make-from-real-imag-rectangular x y) 
  (attach-tag 'rectangular (cons x y)))

(define (make-from-mag-ang-rectangular r a)
  (attach-tag 'rectangular 
               (cons (* r (cos a)) (* r (sin a)))))

;; alyssaの
(define (real-part-polar z)
  (* (magnitude-polar z) (cos (angle-polar z))))

(define (imag-part-polar z)
  (* (magnitude-polar z) (sin (angle-polar z))))

(define (magnitude-polar z) (car z))

(define (angle-polar z) (cdr z))

(define (make-from-real-imag-polar x y)
  (attach-tag 'polar
              (cons (sqrt (+ (square x) (square y)))
                    (atan y x))))

(define (make-from-mag-ang-polar r a) 
  (attach-tag 'polar (cons r a)))


(define (real-part z)
  (cond ((rectangular? z)
         (real-part-rectangular (contents z)))
        ((polar? z)
         (real-part-polar (contents z)))
        (else (error "Unknown type -- REAL-PART" z))))

(define (imag-part z)
  (cond ((rectangular? z)
         (imag-part-rectangular (contents z)))
        ((polar? z)
         (imag-part-polar (contents z)))
        (else (error "Unknown type -- IMAG-PART" z))))


(define (magnitude z)
  (cond ((rectangular? z)
         (magnitude-rectanguler (contents z)))
        ((polar? z)
         (magnitude-polar (contents z)))
        (else (error "Unknown type -- MAGNITUDE" z))))

(define (angle z)
  (cond ((rectangular? z)
         (angle-rectanguler (contents z)))
        ((polar? z)
         (angle-polar (contents z)))
        (else (error "Unknown type -- ANGLE" z))))


;; Benの
(define (install-rectangular-package)
   ;; 内部手続き
  (define (real-part z) (car z))
  (define (imag-part z) (cdr z))
  (define (make-from-real-imag x y) (cons x y))
  (define (magnitude z)
    (sqrt (+ (square (real-part z))
             (square (imag-part z)))))
  (define (angle z)
    (atan (imag-part z) (real-part z)))
  (define (make-from-mag-ang r a) 
    (cons (* r (cos a)) (* r (sin a))))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag 'rectangular x)) 
  (put 'real-part 'rectangular real-part) ; この辺、テキストだと '(rectangular)ってなってるけど本当？
  (put 'imag-part 'rectangular imag-part)
  (put 'magnitude 'rectangular magnitude)
  (put 'angle 'rectangular angle)
  (put 'make-from-real-imag 'rectangular 
       (lambda (x y) (tag (make-from-real-imag x y)))) ; なぜ急にlambda?
  (put 'make-from-mag-ang 'rectangular 
       (lambda (r a) (tag (make-from-mag-ang r a)))) ; なぜ急に
  'done)


; 動かないとどうにもならないので putとgetを作ってみる
(define put-lists '())
(define (clear-putlist)
  (set! put-lists '()))

(define (put op type item)
  (if (get op type) put-lists
  (set! put-lists (cons (list op type item) put-lists)))) ; set!っての使えばやりたいことできそう


(define (get op type) 
  (define (get-operator listItem)
    (car listItem))

  (define (get-type listItem)
    (cadr listItem))

  (define (get-item listItem)
    (caddr listItem))

  (define (get-iter list op type)
    (if (null? list) #f
        (let ((top (car list)))
          (if (and (eq? op (get-operator top))
                   (eq? type (get-type top))) (get-item top)
                   (get-iter (cdr list) op type)))))
  (get-iter put-lists op type))

; ↑どうやら動いているらしい

;; Alyssaの
(define (install-polar-package)
   ;; 内部手続き
  (define (magnitude z) (car z))
  (define (angle z) (cdr z))
  (define (make-from-mag-ang r a) (cons r a))
  (define (real-part z)
    (* (magnitude z) (cos (angle z))))
  (define (imag-part z)
    (* (magnitude z) (sin (angle z))))
  (define (make-from-real-imag x y) 
    (cons (sqrt (+ (square x) (square y)))
          (atan y x)))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag 'polar x))
  (put 'real-part 'polar real-part)
  (put 'imag-part 'polar imag-part)
  (put 'magnitude 'polar magnitude)
  (put 'angle 'polar angle)
  (put 'make-from-real-imag 'polar
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'polar 
       (lambda (r a) (tag (make-from-mag-ang r a))))
  'done)


;;
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op (car type-tags))))
      (if proc
          (apply proc (map contents args))
          (error
           "No method for these types -- APPLY-GENERIC"
           (list op type-tags))))))

(define (real-part z) (apply-generic 'real-part z))
(define (imag-part z) (apply-generic 'imag-part z))
(define (magnitude z) (apply-generic 'magnitude z))
(define (angle z) (apply-generic 'angle z))

(install-rectangular-package)
(install-polar-package)
(get 'make-from-real-imag 'rectangular)
(define (make-from-real-imag x y)
  ((get 'make-from-real-imag 'rectangular) x y))


(define (make-from-mag-ang r a)
  ((get 'make-from-mag-ang 'polar) r a))

(real-part ri-1)

;; 2.73
;; (define (deriv exp var)
;;   (cond ((number? exp) 0)
;;         ((variable? exp) (if (same-variable? exp var) 1 0))
;;         ((sum? exp)
;;          (make-sum (deriv (addend exp) var)
;;                    (deriv (augend exp) var)))
;;         ((product? exp)
;;          (make-sum
;;            (make-product (multiplier exp)
;;                          (deriv (multiplicand exp) var))
;;            (make-product (deriv (multiplier exp) var)
;;                          (multiplicand exp))))
;;         (else (error "unknown expression type -- DERIV" exp))))
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
        (else ((get 'deriv (operator exp)) (operands exp)
               var))))

(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
(define (=number? exp num)
  (and (number? exp) (= exp num)))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))

; a sum? とか product? とかをタグにして複素数の時みたいに表にしてある。sum? にあたるところが operatorで残りがexpに入っている
; number? と variable? はoperator/operandsという形式でないから表に登録ができない？

; b まずsumだけやってみる
(define (install-deriv-package)
   ;; 内部手続き
  (define (addend exp) (car exp))
  (define (augend exp) (cadr exp))
  (define (make-sum a1 a2)
    (cond ((=number? a1 0) a2)
          ((=number? a2 0) a1)
          ((and (number? a1) (number? a2)) (+ a1 a2))
          (else (list '+ a1 a2))))

  (define (sum-deriv operands var)
    (make-sum (deriv (addend operands) var)
              (deriv (augend operands) var)))
  
  ;; システムの他の部分とのインターフェース
  (put 'deriv '+ sum-deriv)
  'done)
(clear-putlist)
(install-deriv-package)
((get 'deriv '+) '(x 3) 'x)
; gosh> 1
; よさげ
; productも突っ込んでみる
(define (install-deriv-package)
  ;; 内部手続き
  ;; '+用 
  (define (addend exp) (car exp))
  (define (augend exp) (cadr exp))
  (define (make-sum a1 a2)
    (cond ((=number? a1 0) a2)
          ((=number? a2 0) a1)
          ((and (number? a1) (number? a2)) (+ a1 a2))
          (else (list '+ a1 a2))))

  ;; '*用
  (define (multipler exp) (car exp))
  (define (multiplicand exp) (cadr exp))
  (define (make-product m1 m2)
    (cond ((or (=number? m1 0) (=number? m2 0)) 0)
          ((=number? m1 1) m2)
          ((=number? m2 1) m1)
          ((and (number? m1) (number? m2)) (* m1 m2))
          (else (list '* m1 m2))))

  ;; 肝心の微分操作
  (define (sum-deriv operands var)
    (make-sum (deriv (addend operands) var)
              (deriv (augend operands) var)))

  (define (product-deriv operands var)
    (make-sum
     (make-product (multiplier operands)
                   (deriv (multiplicand operands) var))
     (make-product (deriv (multiplier operands) var)
                   (multiplicand operands))))
  
  ;; システムの他の部分とのインターフェース
  (put '+ 'deriv sum-deriv)
  (put '* 'deriv product-deriv)
  'done)
(clear-putlist)
(install-deriv-package)

((get 'deriv '+) '(x 3) 'x)
((get 'deriv '*) '(x y) 'x)

; derivしか登録できない。この作りだとoperatorが 'derivになってしまっている気がするんだけど・・
; じゃあinstallするのは演算毎ってことかしら
; これが外に出てるのがなんかダサい。
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
          ((and (number? m1) (number? m2)) (* m1 m2))
          (else (list '* m1 m2))))

;; '+用 
(define (install-deriv-sum)
  ;; 内部手続き
  (define (addend exp) (car exp))
  (define (augend exp) (cadr exp))

  ;; sumの微分
  (define (sum-deriv operands var)
    (make-sum (deriv (addend operands) var)
              (deriv (augend operands) var)))

  (put 'deriv '+ sum-deriv)
  'done)

;; '*用
(define (install-deriv-product)
  (define (multiplier exp) (car exp))
  (define (multiplicand exp) (cadr exp))

  ;; 肝心の微分操作
  (define (product-deriv operands var)
    (make-sum
     (make-product (multiplier operands)
                   (deriv (multiplicand operands) var))
     (make-product (deriv (multiplier operands) var)
                   (multiplicand operands))))
    
  ;; システムの他の部分とのインターフェース
    (put 'deriv '* product-deriv)
  'done)
(clear-putlist)
(install-deriv-sum)
(install-deriv-product)
put-lists
((get 'deriv '+) '(x 3) 'x)
; gosh> 1
((get 'deriv '*) '(x y) 'x)
; gosh> y

;できたげ。
; c
(define (install-deriv-exp)
  ; 内部表現
  (define (base x)
    (car x))
  (define (exponent x)
    (cadr x))
  (define (make-exponentiation base exponent)
    (cond ((=number? exponent 0) 1)
          ((=number? exponent 1) base)
          (else (list '** base exponent))))
  ;; 肝心の微分操作
  (define (exp-deriv operands var)
    (make-product (make-product (exponent operands) 
                                (make-exponentiation (base operands) (- (exponent operands) 1)))
                  (deriv (base operands) var)))
    
  ;; システムの他の部分とのインターフェース
  (put 'deriv '** exp-deriv)
  'done)
(install-deriv-exp)
put-lists

(deriv '(** x 2) 'x)
; gosh> (* 2 x)
;; よさげ。

;; d
; ((get (operator exp) 'deriv) (operands exp) var)
;のばあい
; こっちだと 「operatorで検索して'deriv型だったら演算する」という形になる（最初にイメージしたのはこっちだった)
(define (install-deriv-package)
  ;; 内部手続き
  ;; '+用 
  (define (addend exp) (car exp))
  (define (augend exp) (cadr exp))
  (define (make-sum a1 a2)
    (cond ((=number? a1 0) a2)
          ((=number? a2 0) a1)
          ((and (number? a1) (number? a2)) (+ a1 a2))
          (else (list '+ a1 a2))))

  ;; '*用
  (define (multiplier exp) (car exp))
  (define (multiplicand exp) (cadr exp))
  (define (make-product m1 m2)
    (cond ((or (=number? m1 0) (=number? m2 0)) 0)
          ((=number? m1 1) m2)
          ((=number? m2 1) m1)
          ((and (number? m1) (number? m2)) (* m1 m2))
          (else (list '* m1 m2))))

  ;; 肝心の微分操作
  (define (sum-deriv operands var)
    (make-sum (deriv (addend operands) var)
              (deriv (augend operands) var)))

  (define (product-deriv operands var)
    (make-sum
     (make-product (multiplier operands)
                   (deriv (multiplicand operands) var))
     (make-product (deriv (multiplier operands) var)
                   (multiplicand operands))))
  
  ;; システムの他の部分とのインターフェース
  (put '+ 'deriv sum-deriv)
  (put '* 'deriv product-deriv)
  'done)
(clear-putlist)
(install-deriv-package)
put-lists

(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
        (else ((get (operator exp) 'deriv) (operands exp)
               var))))


((get '+ 'deriv) '(x 3) 'x)
; gosh> 1
((get '* 'deriv) '(x y) 'x)
; gosh> y


;; 2.74
;;    データ主導プログラミングにより, そういう戦略を実装する方法を示せ. 例として各事業所の従業員レコードが, 従業員の名前でキーをつけたレコードの集合からなる一つのファイルで出来ているとする. 集合の構造は事業所毎に異る. 更に各従業員のレコード自体が(事業所毎に異った構造の)集合で, addressとかsalaryという識別子でキーをつけた情報を含んでいる. 

;; a. 本部のために, 指定した従業員ファイルから, 指定した従業員のレコードを検索するget-record手続きを実装せよ. この手続きはどの事業所のファイルに対しても使えなければならない. それぞれの事業所ファイルはどう構造化すべきか説明せよ. 特にどんな型情報が追加されるべきか. 

;; b. 本部のために, いずれの事業所の従業員ファイルからでも与えられた従業員のレコードから, 給与の情報を返すget-salary手続きを実装せよ. この演算が働くためには, レコードをどう構造化すべきか. 

;; c. 本部のために, find-employee-record手続きを実装せよ. すべての事業所ファイルから与えられた従業員のレコードを探し, それを返すものとする. この手続きは引数として従業員の名前と全事業所ファイルのリストをとるものと仮定せよ. 

;; d. この企業が, 別の会社を合併した時, 新しい従業員情報を中央システムに組み込むには, どういう変更をすべきか. 

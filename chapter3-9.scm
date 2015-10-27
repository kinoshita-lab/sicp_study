;; 3.38
;; a
;; Peter, Paul, Mary -> 45
;; Peter, Mary, Paul -> 35
;; Paul, Peter, Mary -> 45
;; Paul, Mary, Peter -> 50
;; Mary, Peter, Paul -> 60
;; Mary, Paul, Peter -> 60

;; b
;; 3.38-b.jpg

;; 3.39
;; 言ってることの意味があんまりわからないけど、上の set!　を 直列化の外に出してみました、ってことだとおもった
;; 101:	    	P1がxを100に設定し, 次にP2がxを101に増加する.
;; 121:		P2がxを11に増加し, 次にP1がxをx掛けるxに設定する.
;; 100:		P1がxに(二回)アクセスし, P2がxを11に設定し, P1がxを設定する.
;; この3つかな。


;; 3.40
;; 1000000 P1がxを100に設定し, 次にP2がxを1000000に設定する.
;; 1000000 P2がxを1000に設定し, 次にP1がxをx掛けるxに設定する.
;; 1000:		P1が(* x x)の評価でxの値に二度アクセスする間にP2がxを10から100に変える.
;; 10000:		P1が(* x x)の評価でxの値に二度アクセスする間にP2がxを10から1000に変える.
;; 100000:		P2が(* x x x)の評価でxの値に3度アクセスする2回めにP1がxを10から100に変える.
;; 10000:		P2が(* x x x)の評価でxの値に3度アクセスする3回めにP1がxを10から100に変える.
;; ;; こうかな。
;; 直列化すると1000000になる。

;; 3.41
;; balanceって値を読むだけで変更はしないのでいらないのでは。

;; 3.42
;; benは3.41の内容諦めてるし・・
;; よさげだけどわからない

;; 複数の共有資源を使う複雑さ
(define (exchange account1 account2)
  (let ((difference (- (account1 'balance)
                       (account2 'balance))))
    ((account1 'withdraw) difference)
    ((account2 'deposit) difference)))

;; 全体のexchange手続きを直列化
(define (make-account-and-serializer balance)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)

  (let ((balance-serializer (make-serializer))) ; ここでserializerを作った上で・・・
    (define (dispatch m)
      (cond ((eq? m 'withdraw) withdraw) ; 各取引をする
            ((eq? m 'deposit) deposit)
            ((eq? m 'balance) balance)
            ((eq? m 'serializer) balance-serializer) ; 取引時にはこれを引っ張ってきて外から参照する必要ができた。
            (else (error "Unknown request -- MAKE-ACCOUNT"
                         m))))
    dispatch))

(define (deposit account amount)
  (let ((s (account 'serializer))
        (d (account 'deposit)))
    ((s d) amount)))

(define (serialized-exchange account1 account2)
  (let ((serializer1 (account1 'serializer))
        (serializer2 (account2 'serializer)))
    ((serializer1 (serializer2 exchange))
     account1
     account2)))

;; 3.43
;; 論ずる方
;; やりたかったことは$10/$20/$30の交換なので、順調に行けば3種類のどこに入っているかが変わるだけで、1アカウントあたりの量が変わることはないのではないか。

;; 残高がおかしくなる場合
;; と
;; 合計がおかしくなる場合
;; の図をかく。

;; 3.44
;; exchangeの時にはdifferenceの値が有効な期間中、2つの口座をロックしないとダメだったけど、transferの場合は1個ずつで完結しているから大丈夫なのではないだろうか。

;; 3.45
;; これ、本文にあったやつと何が違うんだろう？
;; ((eq? m 'withdraw) (balance-serializer withdraw))
;; みたいに、dispatchされる手続きがserializeされて返ってくる。
;; こうしておけば、毎回depositとかの処理でserializerを使う必要がない、ということだと思う。
;; 問題になってるexchangeとかの時、
;; (define (exchange account1 account2)
;;   (let ((difference (- (account1 'balance)
;;                      (account2 'balance))))
;;     ((account1 'withdraw) difference)
;;     ((account2 'deposit) difference)))
;; account1の方見てみると、'balanceのところでaccount1のserializerを拾ってきていて、
;; それをつかって'withdrawしようとしているけど 'balanceですでにロックがかかってるから'withdrawできない。

;; 直列変換器の実装
;; やっとかい　回路のところもそうだったけど基本的な部品を作るのが最後過ぎて動かせない問題が多い
(define (make-serializer)
  (let ((mutex (make-mutex))) ;mutexを作って・・
    (lambda (p)
      (define (serialized-p . args)
        (mutex 'acquire) ; mutexを取得して
        (let ((val (apply p args))) ;関数を実行してvalに結果を入れて
          (mutex 'release) ; mutexを開放する
          val))
      serialized-p))) ;・・という手続きを返す
;; これってletまみれにしなくてもbeginとかで作れるんじゃないのかな。

(define (make-mutex)
  (let ((cell (list false)))
    (define (the-mutex m)
      (cond ((eq? m 'aqcuire)
             (if (test-and-set! cell) ; trueが返ってきたらsetできていない、という動きするのでちょっと注意
                 (the-mutex 'acquire))) ; retry
            ((eq? m 'release) (clear! cell))))
  the-mutex))

(define (clear! cell)
  (set-car! cell false))

(define (test-and-set! cell)
  (if (car cell)
      true
      (begin (set-car! cell true)
             false)))
;; 3.46
;; 絵をかくのがめんどくなってきた
;; carのところからset-car! のところまでの間に別のプロセスがset-carしちゃったら破綻する

;; 3.47
;; a. 相互排除器を使って
;; mutexはtest-and-set!を使って作られているじゃないの。問題の意味がわからない。
;; mutexから先がどうなってるかは気にしないで作れってことだと思えばいいのかな。
(define (make-semaphore-mutex n)
  (let ((mutex (make-mutex))
        (number 0))
    (define (the-semaphore m)
      (cond ((eq? m 'acquire)
             (begin (mutex 'acquire) ;; ここで自動retryになる
                    (if (< number n)
                        (set! number (+ 1 number)))
                    (mutex 'release)))
             ((eq? m 'release)
              (begin (mutex 'acquire)
                     (set! number (- number 1))
                     (if (< number 0)
                         "ERROR"
                         (mutex 'release))))))
    the-semaphore))
                         
;; b. test-and-set!を使って
;; 単純に↑を開けばいいような？
(define (make-semaphore-test-and-set n)
  (let ((list #f)
        (number 0))
    (define (the-semaphore m)
      (cond ((eq? m 'acquire)
             (begin (mutex 'acquire) ;; ここで自動retryになる
                    (if (or (test-and-set! cell) ;; こいつはダメだった時にtrue返すから
                            (>= number n)) ;; さっきのmutex版とは条件を反転させる。
                        (the-semaphore m) ;; 手動retry
                        (begin (set! number (+ 1 number))
                        (clear! cell)))))
             ((eq? m 'release)
              (begin (set! number (- number 1))
                     (if (< number 0)
                         "ERROR"
                         (clear! cell))))))
    the-semaphore))



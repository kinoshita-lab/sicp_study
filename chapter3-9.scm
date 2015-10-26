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




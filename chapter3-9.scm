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

;;; 3.3.4 ディジタル回路のシミュレータ

;; これうごかないよね
;; 写経はする

(define a (make-wire))
(define b (make-wire))
(define c (make-wire))
(define d (make-wire))
(define e (make-wire))
(define s (make-wire))

(or-gate a b d)
(inverter c e)
(and-gate d e s)

;; まあここまで動くとして・・
;; 半加算器
(define (half-adder a b s c)
  (let ((d (make-wire)) (e (make-wire)))
    (or-gate a b d)
    (and-gate a b c)
    (inverter c e)
    (and-gate d e s)
    'ok))

;; 全加算器
(define (full-adder a b c-in sum c-out)
  (let ((s (make-wire))
        (c1 (make-wire))
        (c2 (make-wire)))
    (half-adder b c-in s c1)
    (half-adder a s sum c2)
    (or-gate c1 c2 c-out)
    'ok))


(define (inverter input output)
  (define (inverter-input)
    (let ((new-value (logical-not (get-signal input))))
      (after-delay inverter-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  (add-action! input invert-input)
  'ok)

(define (logical-not s)
  (cond ((= s 0) 1)
        ((= s 1) 0)
        (else (error "Invalid signal" s))))

;; and gate
(define (and-gate a1 a2 output)
  (define (and-action-procedure)
    (let ((new-value
           (logical-and (get-signal a1) (get-signal a2))))
      (after-delay and-gate-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  'ok)
;; これいるでしょ
(define (logical-and a b)
  (cond ((and (= 1 a) (= 1 b)) 1)
        (else 0)))

;; ===============================================
;; 3.28 or gateを作る
(define (or-gate a1 a2 output)
  (define (or-action-procedure)
    (let ((new-value
           (logical-or (get-signal a1) (get-signal a2))))
      (after-delay or-gate-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  'ok)
;; これいるでしょ
(define (logical-or a b)
  (cond ((or (= 1 a) (= 1 b)) 1)
        (else 0)))
;; ===============================================
;; 3.29
;; 知っていればできるけど知らなかったらどうするんだろう
;; まずNANDゲートを作る
(define (nand-gate a b c)
  (let ((d (make-wire)) (e (make-wire)))
    (inverter a d)
    (inverter b e)
    (and-gate d e d)
    'ok))
;; んでそれを3つくっつけてORゲートを作る
(define (compound-or-gate a b c)
  (let ((d (make-wire)) (e (make-wire)))
    (nand-gate a a d)
    (nand-gate b b e)
    (and-gate d e c)
    'ok))
;; 動かないけど。
;; delayは1ゲートあたり　1(inverter-delay)+ 1(and-delay)
;; 2個通るので　2(inverter-delay) + 2(and-delay)
;; ===============================================
;; 3.30
;; これでいいようなきがする
(define (ripple-carry-adder as bs ss cin)
  (define (iter as bs ss cin)
    (if (null? as)
        'ok
        (let ((cout (make-wire)))
          (full-adder (car as) (car bs) cin (car ss) cout)
          (iter (cdr as) (cdr bs) (cdr ss) cout))))
  (iter as bs ss cin))
;; 完全な出力が得られるまでの遅延は, アンドゲート,オアゲートおよびインバータの遅延を使ってどの位か. 
;; half adderで一番時間かかりそうなのは　AND->INV->ANDの道なので
;; half adder1こで 2(AND) + 1(INV)
;; full adderは1こあたりhalf adder x2 と or1個の道が時間かかりそうなので1個あたり
;; 2x(half) + 1or
;; = 4(and) + 1(inv) + 1(or)分の遅延がある
;; nビットだと
;; n x (4and + 1inv + 1or) の時間がかかる。

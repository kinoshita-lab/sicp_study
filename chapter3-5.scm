;; 3.3.2 キューの表現
(use slib)
(require 'trace)

(define (front-ptr queue) (car queue))
(define (rear-ptr queue) (cdr queue))
(define (set-front-ptr! queue item) (set-car! queue item)) ;;この辺でfront-ptr, rear-ptrを使ってくれると3.22がだいぶわかりやすいんだけどなあ。
(define (set-rear-ptr! queue item) (set-cdr! queue item))
(define (empty-queue? queue) (null? (front-ptr queue)))
(define (make-queue) (cons '() '()))
(define (front-queue queue)
  (if (empty-queue? queue)
      (error "FRONT called with an empty queue" queue)
      (car (front-ptr queue))))

(define (insert-queue! queue item)
  (let ((new-pair (cons item '())))
    (cond ((empty-queue? queue)
           (set-front-ptr! queue new-pair)
           (set-rear-ptr! queue new-pair)
           queue)
          (else
           (set-cdr! (rear-ptr queue) new-pair)
           (set-rear-ptr! queue new-pair)
           queue))))

(define (delete-queue! queue)
  (cond ((empty-queue? queue)
         (error "DELETE! called with an empty queue"))
        (else
         (set-front-ptr!  queue (cdr (front-ptr queue)))
         queue)))

;; 3.21
(define q1 (make-queue))
(insert-queue! q1 'a)
(insert-queue! q1 'b)


;; carの中のリストがqueueになっているのでそれを表示すればいいっぽいよね
;; (a b)とかだとリストと区別できないのでなんかそれっぽい感じにしてみる
(define (print-queue queue)
  (define (iter item)
    (if (null? item) '()
        (begin
          (display (car item)) ;; display を使えばいいけど引数が1個に限られる
          (display "->")
          (iter (cdr item)))))
  (iter (car queue)))
(print-queue q1)

;; gosh> a->b->()
;; よさげ。

;; 3.22
;; queue でイチイチ外から入れてたやつを内側のを見るようにすればいいのかな。
(define (make-queue)
  
  (let ((front-ptr '())
        (rear-ptr '()))
    (define (set-front-ptr! item)
      (set! front-ptr item))
    (define (set-rear-ptr! item)
      (set! rear-ptr item))
    (define (empty-queue?)
      (null? front-ptr))
    
    (define (front-queue)
      (if (empty-queue?)
          (error "FRONT called with an empty queue")
          (car front-ptr)))
    
    (define (insert-queue! item)
      (let ((new-pair (cons item '())))
        (cond ((empty-queue?)
               (set-front-ptr! new-pair)
               (set-rear-ptr! new-pair)
               front-ptr)
              (else
               (set-cdr! rear-ptr new-pair)
               (set-rear-ptr! new-pair)
               front-ptr))))
    
    (define (delete-queue!)
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue"))
            (else
             (set-front-ptr! (cdr front-ptr)))))
    
    ;; 外部とのインターフェース
    (define (dispatch m)
      (cond ((eq? m 'insert-queue!) insert-queue!)
            ((eq? m 'delete-queue!) delete-queue!)
            (else
             (error "unknown message.."))))
    dispatch))

(define q2 (make-queue))
q2
;; #<closure (make-queue dispatch)>
((q2 'insert-queue!) 'a)
;; (a)
((q2 'insert-queue!) 'b)
;; (a b)
((q2 'delete-queue!))
;; (b)
((q2 'delete-queue!))
;; ()

;; よさげ

;; 3.23
;; 3.22を改造していくと、rear-delete-queue!をどうやって作ればいいかわからなくなる
(define (make-deque)  
  (let ((front-ptr '())
        (rear-ptr '()))
    (define (set-front-ptr! item)
      (set! front-ptr item))
    (define (set-rear-ptr! item)
      (set! rear-ptr item))
    (define (empty-queue?)
      (null? front-ptr))
    
    (define (front-queue)
      (if (empty-queue?)
          (error "FRONT called with an empty queue")
          (car front-ptr)))
    
    (define (rear-queue) ;; 増えた
      (if (empty-queue?)
          (error "rear called with an empty queue")
          (car rear-ptr)))
    
    (define (rear-insert-queue! item) ;; 旧insert-queue!
      (let ((new-pair (cons item '())))
        (cond ((empty-queue?)
               (set-front-ptr! new-pair)
               (set-rear-ptr! new-pair)
               front-ptr)
              (else
               (set-cdr! rear-ptr new-pair)
               (set-rear-ptr! new-pair)
               front-ptr))))

    (define (front-insert-queue! item) ;; 増えた
      (let ((new-pair (cons item '())))
        (cond ((empty-queue?)
               (set-front-ptr! new-pair)
               (set-rear-ptr! new-pair)
               front-ptr)
              (else
               (set-cdr! new-pair front-ptr) ;;ど頭につっこんでみる
               (set-front-ptr! new-pair)
               front-ptr))))
    
    (define (front-delete-queue!) ;; 旧delete-queue!
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue"))
            (else
             (set-front-ptr! (cdr front-ptr)))))

;;;;;;;;;;;;;;;;;;;;
    ;; 増えた　死
    (define (rear-delete-queue!) 
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue"))
            (else
             (error "死") ;;ここで前のやつが参照したいができない
;;;;;;;;;;;;;;;;;;;;

    ;; 外部とのインターフェース
    (define (dispatch m)
      (cond ((eq? m 'front-insert-queue!) front-insert-queue!)
            ((eq? m 'rear-insert-queue!) rear-insert-queue!)
            ((eq? m 'front-delete-queue!) front-delete-queue!)
            ((eq? m 'rear-delete-queue!) rear-delete-queue!)
            ((eq? m 'front-queue) front-queue)
            ((eq? m 'rear-queue) rear-queue)
            (else
             (error "unknown message.."))))
    dispatch))

(define d1 (make-deque))
d1
((d1 'front-insert-queue!) 'a)
((d1 'front-insert-queue!) 'b)
((d1 'front-insert-queue!) 'c)
;; (c b a)

((d1 'rear-insert-queue!) 'x)
((d1 'rear-insert-queue!) 'y)
((d1 'rear-insert-queue!) 'z)
;; (c b a x y z)

((d1 'front-queue))
;; c

((d1 'rear-queue))
;; z

((d1 'front-delete-queue!))
;; (b a x y z)

((d1 'rear-delete-queue!))
;; 死

;; deque化
;; queueでitemは (値 次)という構造になっているので、(値　次 手前)という風に改造すれば良さそう
(define (make-deque)  
  (let ((front-ptr '())
        (rear-ptr '()))
    (define (set-front-ptr! item)
      (set! front-ptr item))
    (define (set-rear-ptr! item)
      (set! rear-ptr item))
    (define (empty-queue?)
      (null? front-ptr))
    
    (define (front-queue)
      (if (empty-queue?)
          (error "FRONT called with an empty queue")
          (car front-ptr)))
    
    (define (rear-queue)
      (if (empty-queue?)
          (error "rear called with an empty queue")
          (car rear-ptr)))
    
    (define (rear-insert-queue! item) 
      (let ((new-triple (cons item (cons '() '()))));; ここで「(値 次 手前)」という形で追加
        (cond ((empty-queue?)
               (set-front-ptr! new-triple)
               (set-rear-ptr! new-triple)
               front-ptr)
              (else
               (set-cdr! (cdr new-triple) rear-ptr) ;; new-tripleの「手前」にrearを入れる
               (set-car! (cdr rear-ptr) new-triple) ;; rear-ptrの「次」をnew-tripleを更新
               (set-rear-ptr! new-triple) ;;入れ終わったのでrearをnew-tripleに変更
               front-ptr))))

    (define (front-insert-queue! item)
      (let ((new-triple (cons item (cons '() '()))));; ここで「(値 次 手前)」という形で追加
        (cond ((empty-queue?)
               (set-front-ptr! new-triple)
               (set-rear-ptr! new-triple)
               front-ptr)
              (else
               (set-car! (cdr new-triple) front-ptr) ;; new-tripleの「次」にfrontを入れる
               (set-cdr! (cdr front-ptr) new-triple) ;; front-ptrの「手前」にnew-tripleを入れる
               (set-front-ptr! new-triple) ;; 入れ終わったのでfrontをnew-tripleに変更
               front-ptr))))
    
    ;; 変更時も次・手前両方いじる必要がある
    (define (front-delete-queue!)
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue"))
            (else
             (set-front-ptr! (cadr front-ptr)) ;; 
             (set-cdr! (cdr front-ptr) '()) ;; 「手前」はもうなくなったので '()る
             )))

    ;; 問題の場所
    (define (rear-delete-queue!) 
      (cond ((empty-queue?)
             (error "DELETE! called with an empty queue"))
            (else
             (set-rear-ptr! (cddr rear-ptr)) ;; 「手前」を拾ってきてそれに更新
             (set-car! (cdr rear-ptr) '())))) ;; 「次」はもうなくなったので '()る

    ;; 外部とのインターフェース
    (define (dispatch m)
      (cond ((eq? m 'front-insert-queue!) front-insert-queue!)
            ((eq? m 'rear-insert-queue!) rear-insert-queue!)
            ((eq? m 'front-delete-queue!) front-delete-queue!)
            ((eq? m 'rear-delete-queue!) rear-delete-queue!)
            ((eq? m 'front-queue) front-queue)
            ((eq? m 'rear-queue) rear-queue)
            (else
             (error "unknown message.."))))
    dispatch))
(define d1 (make-deque))
d1
((d1 'front-insert-queue!) 'a)
((d1 'front-insert-queue!) 'b)
((d1 'front-insert-queue!) 'c)


((d1 'rear-insert-queue!) 'x)
((d1 'rear-insert-queue!) 'y)
((d1 'rear-insert-queue!) 'z)

;; #0=(c #1=(b #2=(a #3=(x #4=(y (z () . #4#) . #3#) . #2#) . #1#) . #0#))
;; すごいビジュアルになった

((d1 'front-queue))
;; c

((d1 'rear-queue))
;; z

((d1 'front-delete-queue!))
;; b

((d1 'rear-delete-queue!))
((d1 'rear-queue))
;; y

;; できたっぽい

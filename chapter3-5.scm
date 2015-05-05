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



                 

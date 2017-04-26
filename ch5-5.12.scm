;;;;REGISTER-MACHINE SIMULATOR FROM SECTION 5.2 OF
;;;; STRUCTURE AND INTERPRETATION OF COMPUTER PROGRAMS

;;;;Matches code in ch5.scm

;;;;This file can be loaded into Scheme as a whole.
;;;;Then you can define and simulate machines as shown in section 5.2

;;;**NB** there are two versions of make-stack below.
;;; Choose the monitored or unmonitored one by reordering them to put the
;;;  one you want last, or by commenting one of them out.
;;; Also, comment in/out the print-stack-statistics op in make-new-machine
;;; To find this stack code below, look for comments with **
;; これ必要
(define true #t) 
(define false #f)

(define (make-machine register-names ops controller-text)
  (let ((machine (make-new-machine)))
    (for-each (lambda (register-name)
                ((machine 'allocate-register) register-name))
              register-names)
    ((machine 'install-operations) ops)    
    ((machine 'install-instruction-sequence)
     (assemble controller-text machine))
    machine))

(define (make-register name)
  (let ((contents '*unassigned*))
    (define (dispatch message)
      (cond ((eq? message 'get) contents)
            ((eq? message 'set)
             (lambda (value) (set! contents value)))
            (else
             (error "Unknown request -- REGISTER" message))))
    dispatch))

(define (get-contents register)
  (register 'get))

(define (set-contents! register value)
  ((register 'set) value))

;;**original (unmonitored) version from section 5.2.1
(define (make-stack)
  (let ((s '()))
    (define (push x)
      (set! s (cons x s)))
    (define (pop)
      (if (null? s)
          (error "Empty stack -- POP")
          (let ((top (car s)))
            (set! s (cdr s))
            top)))
    (define (initialize)
      (set! s '())
      'done)
    (define (dispatch message)
      (cond ((eq? message 'push) push)
            ((eq? message 'pop) (pop))
            ((eq? message 'initialize) (initialize))
            (else (error "Unknown request -- STACK"
                         message))))
    dispatch))

(define (pop stack)
  (stack 'pop))

(define (push stack value)
  ((stack 'push) value))

;;**monitored version from section 5.2.4
(define (make-stack)
  (let ((s '())
        (number-pushes 0)
        (max-depth 0)
        (current-depth 0))
    (define (push x)
      (set! s (cons x s))
      (set! number-pushes (+ 1 number-pushes))
      (set! current-depth (+ 1 current-depth))
	  (set! max-depth (max current-depth max-depth))) 
	
    (define (pop)
      (if (null? s)
          (error "Empty stack -- POP")
          (let ((top (car s)))
            (set! s (cdr s))
            (set! current-depth (- current-depth 1))
            top)))    
    (define (initialize)
      (set! s '())
      (set! number-pushes 0)
      (set! max-depth 0)
      (set! current-depth 0)
      'done)
    (define (print-statistics)
      (newline)
      (display (list 'total-pushes  '= number-pushes
                     'maximum-depth '= max-depth)))
    (define (dispatch message)
      (cond ((eq? message 'push) push)
            ((eq? message 'pop) (pop))
            ((eq? message 'initialize) (initialize))
            ((eq? message 'print-statistics)
             (print-statistics))
            (else
             (error "Unknown request -- STACK" message))))
    dispatch))
;; gaucheの力でsort/uniq
(use gauche.sequence)
(define (make-new-machine)
  (let ((pc (make-register 'pc))
        (flag (make-register 'flag))
        (stack (make-stack))
        (the-instruction-sequence '()))
    (let ((the-ops
           (list (list 'initialize-stack
                       (lambda () (stack 'initialize)))
                 ;;**next for monitored stack (as in section 5.2.4)
                 ;;  -- comment out if not wanted
                 (list 'print-stack-statistics
                       (lambda () (stack 'print-statistics)))))
          (register-table
           (list (list 'pc pc) (list 'flag flag))))
      (define (allocate-register name)
        (if (assoc name register-table)
            (error "Multiply defined register: " name)
            (set! register-table
                  (cons (list name (make-register name))
                        register-table)))
        'register-allocated)
      (define (lookup-register name)
        (let ((val (assoc name register-table)))
          (if val
              (cadr val)
              (error "Unknown register:" name))))
      (define (execute)
        (let ((insts (get-contents pc)))
          (if (null? insts)
              'done
              (begin
                ((instruction-execution-proc (car insts)))
                (execute)))))
      ;; 5.12 ここから
      ;; listをuniqにするやつを作った
      (define (unique-sequence s)
        (map car (group-sequence s)))
      
      ;; 命令を拾ってくる
      (define (instructions)
        (let* ((tmp1 (map (lambda (insts) (car insts)) the-instruction-sequence))
               (tmp2 (map car tmp1)))
          (sort (unique-sequence tmp2))))

      ;; labelを拾ってくる
      (define (entry-points)
        (let* ((tmp1 (map (lambda (insts) (car insts)) the-instruction-sequence))
               (tmp2 (filter (lambda (inst) (eq? (car inst) 'goto))
                             tmp1)) ;; こんなのになる ((goto (label fib-loop)) (goto (label fib-loop)) (goto (reg continue)) (goto (reg continue)))
               (tmp3 (map cadr tmp2)) ; こんなのになる ((label fib-loop) (label fib-loop) (reg continue) (reg continue))
               (tmp4 (map cadr (filter (lambda (label-or-reg) (eq? (car label-or-reg) 'reg))
                             tmp3)))) 
          (sort (unique-sequence tmp4))))

      ;; 3問目 save restoreを拾ってきてregnameでuniqすればよいやつ
      ;; unique-sequenceがイマイチ仕事してなかったので作った
      (define (uniq-regname regs)
        (let loop ((r regs)
                   (ret '()))
          (if (eq? r '()) ret
              (if (memq (car r) ret)
                  (loop (cdr r) ret)
                  (loop (cdr r) (cons (car r) ret))))))

      (define (save-restore)
        (let* ((tmp1 (map car the-instruction-sequence))
               (tmp2 (filter (lambda (inst) (or (eq? (car inst) 'save)
                                               (eq? (car inst) 'restore))) tmp1))
               ;; save/restoreをけずる
               (tmp3 (map cadr tmp2)))
          (sort (uniq-regname tmp3))))

      ;; 4問目 assignを拾ってくる 
      (define (assigns)
        (let* ((tmp1 (map car the-instruction-sequence)) ;; これでよかった
               (tmp2 (filter (lambda (inst) (eq? (car inst) 'assign)) tmp1)) ;; こんなのが出る ((assign continue (label fib-done)) (assign continue (label afterfib-n-1)) (assign n (op -) (reg n) (const 1)) (assign n (op -) (reg n) (const 2)) (assign continue (label afterfib-n-2)) (assign n (reg val)) (assign val (op +) (reg val) (reg n)) (assign val (reg n)))
               ;; assignを削る
               (tmp3 (map cdr tmp2))) ;; こんなのが出る ((continue (label fib-done)) (continue (label afterfib-n-1)) (n (op -) (reg n) (const 1)) (n (op -) (reg n) (const 2)) (continue (label afterfib-n-2)) (n (reg val)) (val (op +) (reg val) (reg n)) (val (reg n)))
          ;; めんどいのでtmp3をsortすればいいことにする。
          (sort tmp3)))

               


      ;; 5.12ここまで

      (define (dispatch message)
        (cond ((eq? message 'start)
               (set-contents! pc the-instruction-sequence)
               (execute))
              ((eq? message 'install-instruction-sequence)
               (lambda (seq) (set! the-instruction-sequence seq)))
              ((eq? message 'allocate-register) allocate-register)
              ((eq? message 'get-register) lookup-register)
              ((eq? message 'install-operations)
               (lambda (ops) (set! the-ops (append the-ops ops))))
              ((eq? message 'stack) stack)
              ((eq? message 'operations) the-ops)
              ;; ここから下 5.12で増えた
              ((eq? message 'instructions) (instructions))
              ((eq? message 'entry-points) (entry-points))
              ((eq? message 'save-restore) (save-restore))
              ((eq? message 'assigns) (assigns))
              (else (error "Unknown request -- MACHINE" message))))
      dispatch)))


(define (start machine)
  (machine 'start))

(define (get-register-contents machine register-name)
  (get-contents (get-register machine register-name)))

(define (set-register-contents! machine register-name value)
  (set-contents! (get-register machine register-name) value)
  'done)

(define (get-register machine reg-name)
  ((machine 'get-register) reg-name))

(define (assemble controller-text machine)
  (extract-labels controller-text
    (lambda (insts labels)
      (update-insts! insts labels machine)
      insts)))

(define (extract-labels text receive)
  (if (null? text)
      (receive '() '())
      (extract-labels (cdr text)
       (lambda (insts labels)
         (let ((next-inst (car text)))
           (if (symbol? next-inst) ;; ここがlabelの時来るところ
			   (begin
				 (if (assoc next-inst labels) ;; labelは頭についてるのでそこひっかけて
					 (error "duplicate label name" next-inst) ;; かぶってたらerror
					 (receive insts
						 (cons (make-label-entry next-inst
												 insts)
							   labels))))
               (receive (cons (make-instruction next-inst)
                              insts)
				   labels)))))))

(define (update-insts! insts labels machine)
  (let ((pc (get-register machine 'pc))
        (flag (get-register machine 'flag))
        (stack (machine 'stack))
        (ops (machine 'operations)))
    (for-each
     (lambda (inst)
       (set-instruction-execution-proc! 
        inst
        (make-execution-procedure
         (instruction-text inst) labels machine
         pc flag stack ops)))
     insts)))

(define (make-instruction text)
  (cons text '()))

(define (instruction-text inst)
  (car inst))

(define (instruction-execution-proc inst)
  (cdr inst))

(define (set-instruction-execution-proc! inst proc)
  (set-cdr! inst proc))

(define (make-label-entry label-name insts)
  (cons label-name insts))

(define (lookup-label labels label-name)
  (let ((val (assoc label-name labels)))
    (if val
        (cdr val)
        (error "Undefined label -- ASSEMBLE" label-name))))


(define (make-execution-procedure inst labels machine
                                  pc flag stack ops)
  (cond ((eq? (car inst) 'assign)
         (make-assign inst machine labels ops pc))
        ((eq? (car inst) 'test)
         (make-test inst machine labels ops flag pc))
        ((eq? (car inst) 'branch)
         (make-branch inst machine labels flag pc))
        ((eq? (car inst) 'goto)
         (make-goto inst machine labels pc))
        ((eq? (car inst) 'save)
         (make-save inst machine stack pc))
        ((eq? (car inst) 'restore)
         (make-restore inst machine stack pc))
        ((eq? (car inst) 'perform)
         (make-perform inst machine labels ops pc))
		((eq? (car inst) 'clear) ;; 5.10で足した
		 (make-clear inst machine labels ops pc)) ;;5.10で足した
        (else (error "Unknown instruction type -- ASSEMBLE"
                     inst))))

;;; この関数を 5.10で足した
(define (make-clear inst machine labels operations pc)
  (let ((target
         (get-register machine (assign-reg-name inst))))
	(lambda ()                ; execution procedure for clear
	  (set-contents! target 0)
	  (advance-pc pc))))

(define (make-assign inst machine labels operations pc)
  (let ((target
         (get-register machine (assign-reg-name inst)))
        (value-exp (assign-value-exp inst)))
    (let ((value-proc
           (if (operation-exp? value-exp)
               (make-operation-exp
                value-exp machine labels operations)
               (make-primitive-exp
                (car value-exp) machine labels))))
      (lambda ()                ; execution procedure for assign
        (set-contents! target (value-proc))
        (advance-pc pc)))))

(define (assign-reg-name assign-instruction)
  (cadr assign-instruction))

(define (assign-value-exp assign-instruction)
  (cddr assign-instruction))

(define (advance-pc pc)
  (set-contents! pc (cdr (get-contents pc))))

(define (make-test inst machine labels operations flag pc)
  (let ((condition (test-condition inst)))
    (if (operation-exp? condition)
        (let ((condition-proc
               (make-operation-exp
                condition machine labels operations)))
          (lambda ()
            (set-contents! flag (condition-proc))
            (advance-pc pc)))
        (error "Bad TEST instruction -- ASSEMBLE" inst))))

(define (test-condition test-instruction)
  (cdr test-instruction))


(define (make-branch inst machine labels flag pc)
  (let ((dest (branch-dest inst)))
    (if (label-exp? dest)
        (let ((insts
               (lookup-label labels (label-exp-label dest))))
          (lambda ()
            (if (get-contents flag)
                (set-contents! pc insts)
                (advance-pc pc))))
        (error "Bad BRANCH instruction -- ASSEMBLE" inst))))

(define (branch-dest branch-instruction)
  (cadr branch-instruction))


(define (make-goto inst machine labels pc)
  (let ((dest (goto-dest inst)))
    (cond ((label-exp? dest)
           (let ((insts
                  (lookup-label labels
                                (label-exp-label dest))))
             (lambda () (set-contents! pc insts))))
          ((register-exp? dest)
           (let ((reg
                  (get-register machine
                                (register-exp-reg dest))))
             (lambda ()
               (set-contents! pc (get-contents reg)))))
          (else (error "Bad GOTO instruction -- ASSEMBLE"
                       inst)))))

(define (goto-dest goto-instruction)
  (cadr goto-instruction))

(define (make-save inst machine stack pc)
  (let ((reg (get-register machine
                           (stack-inst-reg-name inst))))
    (lambda ()
      (push stack (get-contents reg))
      (advance-pc pc))))

(define (make-restore inst machine stack pc)
  (let ((reg (get-register machine
                           (stack-inst-reg-name inst))))
    (lambda ()
      (set-contents! reg (pop stack))    
      (advance-pc pc))))

(define (stack-inst-reg-name stack-instruction)
  (cadr stack-instruction))

(define (make-perform inst machine labels operations pc)
  (let ((action (perform-action inst)))
    (if (operation-exp? action)
        (let ((action-proc
               (make-operation-exp
                action machine labels operations)))
          (lambda ()
            (action-proc)
            (advance-pc pc)))
        (error "Bad PERFORM instruction -- ASSEMBLE" inst))))

(define (perform-action inst) (cdr inst))

(define (make-primitive-exp exp machine labels)
  (cond ((constant-exp? exp)
         (let ((c (constant-exp-value exp)))
           (lambda () c)))
        ((label-exp? exp)
         (let ((insts
                (lookup-label labels
                              (label-exp-label exp))))
           (lambda () insts)))
        ((register-exp? exp)
         (let ((r (get-register machine
                                (register-exp-reg exp))))
           (lambda () (get-contents r))))
        (else
         (error "Unknown expression type -- ASSEMBLE" exp))))

(define (register-exp? exp) (tagged-list? exp 'reg))

(define (register-exp-reg exp) (cadr exp))

(define (constant-exp? exp) (tagged-list? exp 'const))

(define (constant-exp-value exp) (cadr exp))

(define (label-exp? exp) (tagged-list? exp 'label))

(define (label-exp-label exp) (cadr exp))


(define (make-operation-exp exp machine labels operations)
  (let ((op (lookup-prim (operation-exp-op exp) operations))
        (aprocs
         (map (lambda (e)
				(if (label-exp? e)
					(error "cannot perform label operation!") ;; 5.9で足した
					(make-primitive-exp e machine labels)))
              (operation-exp-operands exp))))
    (lambda ()
      (apply op (map (lambda (p) (p)) aprocs)))))

(define (operation-exp? exp)
  (and (pair? exp) (tagged-list? (car exp) 'op)))
(define (operation-exp-op operation-exp)
  (cadr (car operation-exp)))
(define (operation-exp-operands operation-exp)
  (cdr operation-exp))


(define (lookup-prim symbol operations)
  (let ((val (assoc symbol operations)))
    (if val
        (cadr val)
        (error "Unknown operation -- ASSEMBLE" symbol))))

;; from 4.1
(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))

'(REGISTER SIMULATOR LOADED)

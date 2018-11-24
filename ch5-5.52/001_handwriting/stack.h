#pragma once
#include <stack>
#include "types.h"

/** Simplified version of below, for eceval save/restore
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
*/
class Stack
{
public:
    Stack();
    void initialize();
    void print_statistics();
    void save(SchemeDataType* reg);
    void save(const int registerId);
    SchemeDataType* restore();
    void restore(const int registerId);
    
private:
    std::stack<SchemeDataType*> s;
    std::stack<SchemeDataType*> empty_stack;
    int number_pushes;
    int max_depth;
    int current_depth;
};

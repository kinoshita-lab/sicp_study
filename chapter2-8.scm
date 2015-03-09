(require racket/trace)
(load "./chapter2_utility.scm")
(load "./chapter2_install-packages.scm")
                    
;; 試
(clear-putlist)b
(install-scheme-number-package)
(install-complex-package)
(install-rectangular-package)
(put-coercion 'scheme-number 'complex scheme-number->complex)
(define a (make-scheme-number 10))
a
(define b (make-complex-from-real-imag 1 2))
(trace apply-generic)
(trace get)
(add a b)

put-lists


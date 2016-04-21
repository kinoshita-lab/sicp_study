;; 4. 1. 5 プログラムとしてのデータ
;; gaucheではuser-initial-environment的なものは
;; (interaction-environment) で拾える
(eval '(* 5 5) (interaction-environment))
;; > 25
(eval (cons '* (list 5 5)) (interaction-environment))
;; > 25


;; 4.15
;; 背理法だ
;; try を(try try)って呼ぶと
;; 止まる場合　run-foreverになって止まらない
;; 止まらない場合 'haltedが戻ってきて止まる
;; ので矛盾してる。

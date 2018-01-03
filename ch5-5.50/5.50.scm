;; 5.50
;; いろいろなものを元の状態にもどさないとわけわかになっているな。
;; eveval-compilerにmcevalを読むってことか。どうなるのかな。
(load "./mceval-for-5.50.scm") ;; 問題にかいてあったとおりbeginでくるんだ
(load "./ch5-eceval-compiler.scm")
;; いきなりgo
(compile-and-go mceval)
;; gosh> *** ERROR: Unbound variable list
;; だめだったじゃん!
;; primitive-procedureに入れればいいのかな。なんかずるい気もするけど
;;; EC-Eval input:
(driver-loop)
;; ってやるといけるのだよねきっと
;; *** ERROR: Unbound variable newline
;; *** ERROR: Unbound variable output
;; letがうまくうごいてないきがする わからん。
;; http://www.serendip.ws/archives/4020
;; http://himoiku.cocolog-nifty.com/blog/2008/07/sicp550_f385.html
;; などを参考にしてみた。
(load "./ch5-eceval-compiler.scm")
(load "./mceval-for-5.50.scm") 

(compile-and-go mceval)
(driver-loop)
;; *** ERROR: Unbound variable initial-env
;; うーん、 どうにもうまくいかない。
;; 回答てきなものを見てみたがmcevalが2回定義されてたりして謎

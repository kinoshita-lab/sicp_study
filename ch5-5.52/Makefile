target = compiled-cpp-program

CC = clang++
CFLAGS = -std=c++14 -g3

SRCS = main.cpp types.cpp global.cpp cons_man.cpp user_print.cpp


$(target) : loader.scm out2cpp $(SRCS)
	./loader.scm
	./out2cpp compiled.out
	clang-format compiled.cpp > tmp.cpp
	mv tmp.cpp compiled.cpp
	$(CC) $(CFLAGS) $(SRCS) compiled.cpp -o $@ -lgc

clean :
	rm -f ./compiled.cpp $(target)

.phony : clean

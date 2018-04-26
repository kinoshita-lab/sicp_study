target = compiled-cpp-program

CC = clang++
CFLAGS = -std=c++14 -g3

SRCS = main.cpp


$(target) : loader.scm out2cpp $(SRCS)
	./loader.scm
	./out2cpp compiled.out
	$(CC) $(CFLAGS) $(SRCS) compiled.cpp -o $@

clean :
	rm -f ./compiled.cpp $(target)

.phony : clean

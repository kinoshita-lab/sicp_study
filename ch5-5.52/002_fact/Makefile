TARGET = fact

CXX = g++
CFLAGS = -g3 -std=c++14 # zatsu	
CFLAGS += -DGC_NEW_ABORTS_ON_OOM # workaround for link error	
RM = rm -f

SRCS = compiled.cpp compiled.out.wrapper.cpp env.cpp global.cpp main.cpp stack.cpp user_print.cpp cons_man.cpp frames.cpp goto_with_label.cpp primitives.cpp types.cpp support.cpp syntax.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

.SUFFIXES: .o .cpp

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@ -lgc

.cpp.o:
	$(CXX) $(CFLAGS) -MMD -c ./$<

.phony: clean all
clean:
	$(RM) $(OBJS) *.d

-include $(DEPS)

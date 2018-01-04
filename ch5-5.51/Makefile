TARGET = eceval

CXX = clang++
CFLAGS = -g3 -std=c++14 # zatsu	
RM = rm -f

SRCS = $(shell ls *.cpp) #zatsu
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

.SUFFIXES: .o .cpp

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) -MMD -c $<

.phony: clean all
clean:
	$(RM) $(OBJS) *.d

-include $(DEPS)

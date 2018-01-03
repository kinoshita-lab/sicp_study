TARGET = eceval

CXX = clang++
CFLAGS = -Og -std=c++14 # zatsu	
RM = rm -f

SRCS = $(shell ls *.cpp) #zatsu
OBJS = $(SRCS:%.cpp=%.o)

.SUFFIXES: .o .cpp

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) -MMD -c $<

.phony: clean
clean:
	$(RM) $(OBJS) *.d

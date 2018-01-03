TARGET = eceval

CXX = clang++
CFLAGS = -Og # zatsu
RM = rm -f

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)

.SUFFIXES: .o .cpp

$(TARGET) : $(OBJS)
	$(CXX) $(SRCS) -o $@

.cpp.o:
	$(CXX) $(CFLAGS) -MMD -c $<

.phony: clean
clean:
	$(RM) $(OBJS) *.d

.phony: clean all

OBJS = test

CXXFLAGS = -O3 -g -Wall -Wpedantic -Wextra -Wshadow -Wunused -Wunused-parameter  -Wunused -Wuninitialized -Wshadow -Werror -Wmisleading-indentation -Wconversion  -std=c++17 

all: ${OBJS}

test: Stack.h


clean:
	rm -f ${OBJS} *.o

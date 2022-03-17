CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
TESTS=./tests/*
OBJ=./src/heap.o ./src/evalexpr.o ./src/vector_op.o
MAIN=./src/main.o

all: evalexpr

evalexpr: $(OBJ) $(MAIN)
	$(CC) $(CLAGS) $(OBJ) $(MAIN) -o evalexpr

library: $(OBJ)
	ar csr libevalexpr.a $(OBJ)

testsuite: $(TESTS) library
	$(CC) $(CFLAGS) $(TESTS) -L. -levalexpr -lcriterion -o testsuite

check: testsuite
	./testsuite

clean:
	$(RM) $(OBJ) evalexpr testsuite libevalexpr.a $(MAIN)


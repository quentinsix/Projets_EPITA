CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
TESTS=./tests/*
OBJ=./src/my_fnmatch.o


all: check

library: $(OBJ)
	ar csr libfnmatch.a $(OBJ)

test: $(TESTS) library
	$(CC) $(CFLAGS) $(TESTS) -L. -lfnmatch -lcriterion -o runsuite

check: test
	./runsuite

clean:
	$(RM) runsuite libfnmatch.a $(OBJ)

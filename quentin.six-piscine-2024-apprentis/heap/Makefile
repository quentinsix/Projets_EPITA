CC = gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
OBJ= add.o create.o del.o pop.o print.o

all: library

library: $(OBJ)
	ar csr libheap.a $(OBJ)

clean:
	$(RM) $(OBJ) libheap.a

CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
OBJ=vector.o

all: library

library: $(OBJ)
	ar csr libvector.a $(OBJ)

clean:
	$(RM) $(OBJ) libvector.a a.out

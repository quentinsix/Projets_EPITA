CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
OBJ=fifo.o


all:

library: $(OBJ)
	ar csr libfifo.a $(OBJ)

check: library
	$(CC) $(CFLAGS) -L. -lfifo.a

clean:
	$(RM) libfifo.a $(OBJ) a.out


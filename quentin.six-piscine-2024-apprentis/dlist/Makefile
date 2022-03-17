CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra
OBJ=dlist1.o dlist2.o dlist3.o

all: library

library: $(OBJ)
	ar csr libdlist.a $(OBJ)

clean:
	$(RM) $(OBJ) libdlist.a


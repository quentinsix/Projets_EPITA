CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o isqrt.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

isqrt.o: isqrt.c isqrt.h
	$(CC) -c isqrt.c

clean:
	rm *.o  main

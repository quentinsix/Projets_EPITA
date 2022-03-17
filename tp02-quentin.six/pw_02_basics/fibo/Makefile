CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o fibo.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

fibo.o: fibo.c fibo.h
	$(CC) -c fibo.c

clean:
	rm *.o  main

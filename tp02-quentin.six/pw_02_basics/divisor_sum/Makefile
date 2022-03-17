CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o divisor_sum.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

divisor_sum.o: divisor_sum.c divisor_sum.h
	$(CC) -c divisor_sum.c

clean:
	rm *.o  main

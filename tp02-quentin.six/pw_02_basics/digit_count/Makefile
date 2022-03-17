CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o digit_count.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

digit_count.o: digit_count.c digit_count.h
	$(CC) -c digit_count.c

clean:
	rm *.o  main

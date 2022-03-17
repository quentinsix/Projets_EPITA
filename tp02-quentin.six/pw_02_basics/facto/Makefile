CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o facto.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

facto.o: facto.c facto.h
	$(CC) -c facto.c

clean:
	rm *.o  main

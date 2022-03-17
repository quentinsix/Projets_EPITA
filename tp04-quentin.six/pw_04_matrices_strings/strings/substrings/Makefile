
CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o
	$(CC) $(CDFLAGS) -o main *.c

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o  main *~

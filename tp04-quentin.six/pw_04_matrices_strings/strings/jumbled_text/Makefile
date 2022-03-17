CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o mix.o
	$(CC) $(CDFLAGS) -o main *.c

main.o: main.c 
	$(CC) -c main.c

mix.o: mix.c mix.h
	$(CC) -c mix.c

clean:
	rm *.o  main *~

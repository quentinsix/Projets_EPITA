CFLAGS = -Wall -Wextra -Werror -std=99 -01
CC = gcc
main: main.o power_of_two.o
	$(CC) $(CDFLAGS) -o main *.c


main.o: main.c
	$(CC) -c main.c

power_of_two.o: power_of_two.c power_of_two.h
	$(CC) -c power_of_two.c

clean:
	rm *.o  main

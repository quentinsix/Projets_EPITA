CFLAGS = -Wall -Werror -std=c99 -fsanitize=address
CC =gcc
backprop: main.o backprop.o layer.o neuron.o neural_network.o networkSaver.o
	$(CC) $(CFLAGS) -o main main.o backprop.o layer.o neuron.o neural_network.o networkSaver.o -lm


main.o: main.c
	$(CC) $(CFLAGS) -c main.c

backprop.o: backprop.c
	$(CC) $(CFLAGS) -c ../Reseau/backprop.c

layer.o: layer.c
	$(CC) $(CFLAGS) -c layer.c

neuron.o: neuron.c
	$(CC) $(CFLAGS) -c neuron.c

neural_network.o: neural_network.c
	$(CC) $(CFLAGS) -c neural_network.c

networkSaver.o: networkSaver.c
	$(CC) $(CFLAGS) -c networkSaver.c

clean:
	rm *.o *~ main

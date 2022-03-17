#ifndef BACKPROP_H
#define BACKPROP_H

#include "layer.h"
#include "neural_network.h"

//every functions used or linked to neural network
void feed_input(int i,network n_n);
void calculate_final_cost(int i,network n_n);
void back_prop(int p,network n_n);
void update_weights_biases(network n_n);
void train_neural_net(network n_n);
void forward(network n_n);
void test_nn(network n_n);
void init_weights_biases(network n_n, int isLoaded);

void final_nn(network n_n);
void freeall(network *n_n);

#endif


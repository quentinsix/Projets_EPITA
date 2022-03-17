#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "layer.h"

//here's the structure for the neural network
typedef struct neural_network
{
	//it has a number of layers
	int num_lay;

	//every layers of the neural net
	layer *layer;
	//its learning rate
	float alpha;

	//its desired_output(s) (for the training)
	float **input;

	//its input(s) (for the training mayber) to test if it work correctly
	float **desired_output;

	//number of neurons in each layer
	int *num_neurons;

	//its number of training exemple
	int num_training_ex;

	//cost of the neural network
	double *cost;

	//the final cost
	double final_cost;
	 
} network;

network create_neural_network(int num_layers, float alpha,int num_training_ex);


#endif
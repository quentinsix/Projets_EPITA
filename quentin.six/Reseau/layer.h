#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"

//here's the structure for one layer
typedef struct layer_t
{
	//it has a number of neurons
	int num_neu;

	//à commenter
	struct neuron_t *neu; 
} layer;

layer create_layer(int num_neurons);

#endif
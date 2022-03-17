#include "layer.h"

//a function returning a structure layer
layer create_layer(int number_of_neurons)
{
	//we create a layer called "lay"
	layer lay;

	//at first the number of neurons in layer is set to 0
	lay.num_neu = 0;

	//it's pointer "neu" points on a structure "neuron_t", wich is in fact 
	//the first neuron in the layer if it has more than one
	lay.neu = (struct neuron_t *) malloc(number_of_neurons * sizeof(struct neuron_t));
	return lay;
}


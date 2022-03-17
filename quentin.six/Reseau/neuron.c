#include "neuron.h"

//when we create the neuron
neuron create_neuron(int num_out_weights)
{
	neuron neu;
	//At first every parameters is set to 0 because nothing happened yet
	neu.actv = 0.0;

	//if there is n neurons in the next layer the current neuron will
	//have n weights, that's why we allocate in the memery this size
	neu.out_weights = (float*) malloc(num_out_weights * sizeof(float));
	neu.bias=0.0;
	neu.z = 0.0;

	//partial derivatives of parameters
	neu.dactv = 0.0;
	neu.dw = (float*) malloc(num_out_weights * sizeof(float));
	neu.dbias = 0.0;
	neu.dz = 0.0;

	return neu;
}

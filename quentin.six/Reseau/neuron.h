#ifndef NEURON_H
#define NEURON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//here's the structure for one neuron
typedef struct neuron_t
{
	//it's activation value (when we use the sigmoid function for exemple)
	//the outuput value of the neuron
	float actv;

	//a pointer pointing on the differents weights the neuron can have
	//the pointer will point on the first one
	//for exemple if the next layer has 3 neurons we will have this pointer
	//pointing on the weight between this neuron and the first neuron of
	//the next layer
	float *out_weights;

	//the value of it's bias
	float bias;

	//the value of sum of every weights*actv(of previous layer)+bias
	float z;


	//the partial derivative of it's activation value
	float dactv;

	//on pointer pointing on the partial derivatives of the differents weights
	float *dw;

	//the partial derivative of the bias
	float dbias;

	//the partial derivative of the z function
	float dz;

} neuron;

neuron create_neuron(int num_out_weights);

#endif
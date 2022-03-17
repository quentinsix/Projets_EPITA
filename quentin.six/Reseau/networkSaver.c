#include <stdio.h>
#include <stdlib.h>
#include "neural_network.h"

void neuralSave(network n_n)
{
    int i,j,k;
    FILE *fPointer;
    FILE *fBias;
    fPointer = fopen("weights.save", "w");
    fBias = fopen("biases.save", "w");
    printf("--------------------Saving weights and biases into new files...--------------------\n\n");

    for(i = 0; i < n_n.num_lay - 1; i++)
    {
        for(j = 0; j < n_n.num_neurons[i]; j++)
        {
            for(k = 0; k < n_n.num_neurons[i + 1]; k++)
            {
                fprintf(fPointer, "%f ", n_n.layer[i].neu[j].out_weights[k]);
            }
            fprintf(fBias, "%f ", n_n.layer[i].neu[j].bias);
            fprintf(fPointer, "\n\n");
            fprintf(fBias, "\n\n");
        }
        fprintf(fPointer, "\n\n");
        fprintf(fBias, "\n\n"); // next layer
    }
    fclose(fPointer);
    for(j=0; j < n_n.num_neurons[n_n.num_lay-1]; j++)
    {
        fprintf(fBias, "%f ", n_n.layer[n_n.num_lay-1].neu[j].bias);
    }
    fclose(fBias);
    printf("--------------------Save files have been written.--------------------\n\n");
}

void neuralLoad(network n_n, FILE *fPointer, FILE *fBias)
{
    int i = 0,j = 0,k = 0;
    float x[12];
    float bias[12];
    while ((fscanf(fPointer, "%12f", x) == 1))
    {
    //printf("poids avant boucle: %f\n", *x); // TO REMOVE

        if( k < n_n.num_neurons[i+1])
        {
            //printf("poids: %f\n", *x); // TO REMOVE
            n_n.layer[i].neu[j].out_weights[k] = *x;
            k++;
        }
        else if(j < n_n.num_neurons[i] - 1)
        {
            j++;
            k = 0;
            //printf("poids 2: %f\n", *x); // TO REMOVE
            n_n.layer[i].neu[j].out_weights[k] = *x;
            k++;
        }
        else if(i < n_n.num_lay - 1)
        {
            i++;
            j = 0;
            k = 0;
            //printf("poids 3: %f\n", *x); // TO REMOVE
            n_n.layer[i].neu[j].out_weights[k] = *x;
            k++;

        }
    }
    fclose(fPointer);
    i = 0, j = 0;
    while(fscanf(fBias, "%12f", bias) == 1) 
    {
         //printf("poids avant boucle: %f\n", *bias); // TO REMOVE

        if (j<n_n.num_neurons[i] && i < n_n.num_lay) 
        {
            //printf("poids 1: %f\n", *bias); // TO REMOVE
            n_n.layer[i].neu[j].bias = *bias;
            j++;
        }
        else if(i < n_n.num_lay)
        {
            //printf("poids 2: %f\n", *bias); // TO REMOVE
            i++;
            j = 0;
            n_n.layer[i].neu[j].bias = *bias;
            j++;
        }
    }
    fclose(fBias);
}


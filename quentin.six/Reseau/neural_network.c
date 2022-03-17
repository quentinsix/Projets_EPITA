#include "neural_network.h"

#include <stdlib.h>
//when we create the neural_network
network create_neural_network(int num_layers,float alpha,int num_training_ex)
{

	int i;
	network neural_net;

	neural_net.layer = NULL;
	
	neural_net.alpha = alpha;

	neural_net.num_lay=num_layers;

	neural_net.num_neurons = (int*) malloc(num_layers * sizeof(int));
    memset(neural_net.num_neurons,0,num_layers *sizeof(int));



    //structure of the neural network
    neural_net.num_neurons[0]=30*30;
    //à changer ??
    neural_net.num_neurons[1]=16;
    //tous les char de l'alphabet en min et maj
    neural_net.num_neurons[2]=52;

    neural_net.num_training_ex=num_training_ex;

    neural_net.input = (float**) malloc(neural_net.num_training_ex * sizeof(float*));
    //alocating memory
    for(i=0;i<neural_net.num_training_ex;i++)
    {
        neural_net.input[i] = (float*)malloc(neural_net.num_neurons[0] * sizeof(float));
    }

    neural_net.desired_output = (float**) malloc(neural_net.num_training_ex* sizeof(float*));

    for(i=0;i<neural_net.num_training_ex;i++)
    {
        neural_net.desired_output[i] = (float*)malloc(neural_net.num_neurons[num_layers-1] * sizeof(float));
    }

    neural_net.cost = (double *) malloc(neural_net.num_neurons[neural_net.num_lay-1] * sizeof(double));
    memset(neural_net.cost,0,neural_net.num_neurons[neural_net.num_lay-1]*sizeof(double));

    //set the training exemples
    for(i=0;i<num_training_ex;i++)
    {
        //chemin par rapport à la place de l'exec
        char filename_format[] = "../Reseau/Training_Set/%d.txt";
        char filename[sizeof(filename_format) + 2];
        snprintf(filename, sizeof(filename), filename_format, i);
        FILE *fp = fopen(filename, "r");
        if(fp==NULL)
        {
            printf("pas de fichier pour le training %d\n",i);
        }

        int k=0;
        char ch;

        while((ch=fgetc(fp))!=EOF)
        {
            
            if(ch!='\n')
            {
                neural_net.input[i][k]=ch-'0';
                k++;
            }
            
        }

        fclose(fp);
    }

        for(int z=0;z<num_training_ex;z++)
    {
        for(int k=0;k<52;k++)
        {
            
            if((z%52)==k)
            {
                
                neural_net.desired_output[z][k]=1;
            }
            else
            {
                neural_net.desired_output[z][k]=0;
            }
        }
     
    }


    int j=0;
    i=0;

    //creation of the structre
    neural_net.layer = (layer*) malloc(num_layers * sizeof(layer));

    for(i=0;i<neural_net.num_lay;i++)
    {
        neural_net.layer[i] = create_layer(neural_net.num_neurons[i]);      
        neural_net.layer[i].num_neu = neural_net.num_neurons[i];
        // printf("Layer %d-th created\n", i+1);
        // printf("Layer %d has %d neurons\n", i+1,neural_net.layer[i].num_neu);

        for(j=0;j<neural_net.num_neurons[i];j++)
        {
            if(i < (num_layers-1)) 
            {
                neural_net.layer[i].neu[j] = create_neuron(neural_net.num_neurons[i+1]);
            }

            // printf("Neuron %d in layer %d created\n",j+1,i+1);  
        }
        // printf("\n");
    }

	return neural_net;
}


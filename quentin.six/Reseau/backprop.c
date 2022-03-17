#include "backprop.h"
#include "layer.h"
#include "neural_network.h"
#include "neuron.h"
#include <time.h>
#include "networkSaver.h"
#include <stdlib.h>


int n=1;

void freeall(network *n_n)
{
    // FREE THE NETWORK STRUCTURE
    for(int i = 0; i < n_n->num_training_ex; i++)
    {
        free(n_n->input[i]);
        free(n_n->desired_output[i]);
    }
    free(n_n->input);
    free(n_n->desired_output);
    free(n_n->cost);
    for(int i = 0; i < n_n->num_lay-1; i++)
    {
        
        for(int j = 0; j < n_n->num_neurons[i]; j++)
        {
            free(n_n->layer[i].neu[j].out_weights);
            free(n_n->layer[i].neu[j].dw);

        }
        free(n_n->layer[i].neu);
    }
    free(n_n->layer[(n_n->num_lay)-1].neu);
    free(n_n->num_neurons);
    free(n_n->layer);
}


// Feed inputs to input layer
void feed_input(int i,network n_n)
{
    
    //num_neurons[0] = numbers neurons in the first layer
    for(int j=0;j<n_n.num_neurons[0];j++)
    {
        n_n.layer[0].neu[j].actv = n_n.input[i][j];
    }
    
}

//function to init every weights and biases in the neural network
// DOIS RAJOUTER PARAMETRE BOOL POUR DEMANDER SI ON DOIT INIT SEULEMENT LES
// BIAIS DANS LE CAS OU ON A CHARGÉ UN FICHIER
void init_weights_biases(network n_n, int isLoaded)
{
    int i,j,k;
    
    // printf("Initializing weights in the neural network :\n");

    //for every layer in the neural network exept for the output layer
    for(i=0;i<n_n.num_lay-1;i++)
    {
        // printf("For the layer : %d\n", i);
        //for every neurons the i-th layer
        for(j=0;j<n_n.num_neurons[i];j++)
        {
            // printf(" Weights and bias of the %dth neurons\n",j);
            //we initialise the (number of neurons in the next layer) weights 
            for(k=0;k<n_n.num_neurons[i+1];k++)
            {

                if(isLoaded == 0)
                    n_n.layer[i].neu[j].out_weights[k] = sin(rand());
                // printf("    %d:weight[%d][%d]: %f\n",k,i,j, n_n.layer[i].neu[j].out_weights[k]);
                n_n.layer[i].neu[j].dw[k] = 0.0;
            }

            //we also initialize the biases
            if(isLoaded == 0)
                n_n.layer[i].neu[j].bias = sin(rand());

            // printf("    %d:biais[%d][%d]: %f\n",k,i,j, n_n.layer[i].neu[j].bias);
            
           
        }
    }
    // printf("For the last layer (only has biases) :\n");
    //if we are on the ouput layer we only initialize the biases
    for (j=0;j<n_n.num_neurons[n_n.num_lay-1];j++)
    {

        if(isLoaded == 0) 
            n_n.layer[n_n.num_lay-1].neu[j].bias = sin(rand());
        // printf("    %d:biais[%d][%d]: %f\n",k,i,j, n_n.layer[n_n.num_lay-1].neu[j].bias);
    }

}


//Train Neural Network
void train_neural_net(network n_n)
{
    
    //Gradient Descent, a=nb of epochs
    for(int a=0;a<200;a++)
    {
        for(int i=0;i<n_n.num_training_ex;i++)
        {
            // printf("%d\n",i );
            feed_input(i,n_n);
            forward(n_n);
            calculate_final_cost(i,n_n);
            back_prop(i,n_n);
            update_weights_biases(n_n);
            
        }
    }

}

//a fct to update weights and biases when back_prop is done
void update_weights_biases(network n_n)
{
    int i;
    for( i=0;i<n_n.num_lay-1;i++)
    {
        for(int j=0;j<n_n.num_neurons[i];j++)
        {
            //for every weights
            for(int k=0;k<n_n.num_neurons[i+1];k++)
            {
                //when the weight is updated we just apply the formula
                n_n.layer[i].neu[j].out_weights[k] = (n_n.layer[i].neu[j].out_weights[k]) - (n_n.alpha * n_n.layer[i].neu[j].dw[k]);
            }
            
            //when the bias is updated we just apply the formula
            n_n.layer[i].neu[j].bias = n_n.layer[i].neu[j].bias - (n_n.alpha * n_n.layer[i].neu[j].dbias);
        }
    }

    //update biases of the output layer
    for(int j=0;j<n_n.num_neurons[n_n.num_lay-1];j++)
    {
        //same formula than before
        n_n.layer[n_n.num_lay-1].neu[j].bias = n_n.layer[i].neu[j].bias - (n_n.alpha * n_n.layer[i].neu[j].dbias);
    }
}


//feed forward
void forward(network n_n)
{
    //for every layer exept the first one,
    for(int i=1;i<n_n.num_lay;i++)
    {   

        for(int j=0;j<n_n.num_neurons[i];j++)
        {

            n_n.layer[i].neu[j].z =0;
            //for every neuron in the previous layer
            for(int k=0;k<n_n.num_neurons[i-1];k++)
            {
                //the mathemical formula : Sum(activation*weigth)+bias
                n_n.layer[i].neu[j].z  = n_n.layer[i].neu[j].z +  ((n_n.layer[i-1].neu[k].out_weights[j])* (n_n.layer[i-1].neu[k].actv));
            }
            n_n.layer[i].neu[j].z += n_n.layer[i].neu[j].bias;

            //sigmoid fct for hidden layer
            if(i < n_n.num_lay-1)
            {
                n_n.layer[i].neu[j].actv = 1/(1+exp(-n_n.layer[i].neu[j].z));     
            }

        }
    }

    //for the softmax function
    double sum_exp_z=0;
    int nb=n_n.num_lay-1;
    for(int j=0;j<n_n.num_neurons[nb];j++)
    {
        sum_exp_z+=exp(n_n.layer[nb].neu[j].z);
    }
    //softmax function
    for(int i=0;i<n_n.num_neurons[nb];i++)
    {
        n_n.layer[nb].neu[i].actv=exp(n_n.layer[nb].neu[i].z)/sum_exp_z;
        // printf("%d", (int)round(n_n.layer[nb].neu[i].actv));
    }

}

//calculation of the total cost (used to see if the neural network works)
void calculate_final_cost(int i,network n_n)
{
    double tmpcost=0;
    double tcost=0;
    //we just apply the formula (quadratic cost function)
    for(int j=0;j<n_n.num_neurons[n_n.num_lay-1];j++)
    {
        tmpcost = (double)(n_n.desired_output[i][j]) - (double)(n_n.layer[n_n.num_lay-1].neu[j].actv);
        n_n.cost[j] = (tmpcost * tmpcost);
        tcost = tcost + n_n.cost[j];
    }   

    //n is the number of training exemple, it's not constant because
    //the first time we only have 1 exemple, the second time 2 etc...
    n_n.final_cost = (n_n.final_cost + tcost)/(2*n);
    n++;
    //just to see smth on the prompt and not do anything
    if (n%(156*4)==0)
    {
        printf("The cost is : %lf \n", n_n.final_cost);
    }
}



//backpropagation, this is only the application of the differents formula
void back_prop(int p,network n_n)
{
    int i,j,k;

    //only for the output layer
    for(j=0;j<n_n.num_neurons[n_n.num_lay-1];j++)
    {           
        //value used in every partial derivative
        n_n.layer[n_n.num_lay-1].neu[j].dz = (n_n.layer[n_n.num_lay-1].neu[j].actv - n_n.desired_output[p][j]) * (n_n.layer[n_n.num_lay-1].neu[j].actv) * (1- n_n.layer[n_n.num_lay-1].neu[j].actv);

        for(k=0;k<n_n.num_neurons[n_n.num_lay-2];k++)
        {   
            //value of partial derivative of weight
            n_n.layer[n_n.num_lay-2].neu[k].dw[j] = (n_n.layer[n_n.num_lay-1].neu[j].dz * n_n.layer[n_n.num_lay-2].neu[k].actv);

        }
        
        //value of partial derivative of bias
        n_n.layer[n_n.num_lay-1].neu[j].dbias = n_n.layer[n_n.num_lay-1].neu[j].dz;
    }

    //for the hidden layers
    for(i=n_n.num_lay-2;i>0;i--)
    {
        for(j=0;j<n_n.num_neurons[i];j++)
        {
            n_n.layer[i].neu[j].dz=(n_n.layer[i].neu[j].actv) * (1- n_n.layer[i].neu[j].actv);
            double somme_w=0;
            for(int a=0;a<n_n.num_neurons[i+1];a++)
            {
                somme_w+=n_n.layer[i].neu[j].dw[a]*n_n.layer[i].neu[j].out_weights[a];
            }

            for( k =0;k<n_n.num_neurons[i-1];k++)
            {
                //manque qqch
                n_n.layer[i-1].neu[k].dw[j]=n_n.layer[i].neu[j].dz*n_n.layer[i-1].neu[k].actv*somme_w;
            }

            //value of partial derivative of bias manque qqch
            n_n.layer[i].neu[j].dbias = n_n.layer[i].neu[j].dz*somme_w;

        }

        
    }
}


//save the output in a txt file
void test_nn(network n_n) 
{

    for(int i=0;i<n_n.num_training_ex;i++)
    {
        //chemin par rapport à l'exec
        char filename_format[] = "../Reseau/Training_Set/%d.txt";
        char filename[sizeof(filename_format) + 2];
        
        snprintf(filename, sizeof(filename), filename_format, i);
        FILE *fp = fopen(filename, "r");
        if(fp==NULL)
        {
            printf("pas de fichier pour le test\n");
        }
        int k=0;
        char ch;
        //for every char in the .txt
        while((ch=fgetc(fp))!=EOF)
        {
            
            if(ch!='\n')
            {
                n_n.layer[0].neu[k].actv=ch-'0';
                k++;
            }
            
        }
        forward(n_n);        
        for(int j=0;j<52;j++)
            {
                
            if((int)round(n_n.layer[2].neu[j].actv)==1)
            {
                if(j<26)
                {
                    printf("%c",(char)(j+65));
                }
                else
                {
                    printf("%c",(char)(j+71));
                }
            }
            }
            if((i+1)%52==0)
            {
                printf("\n");
            }
        fclose(fp);
    }

    //when the fct is over we free the allocated memory
    freeall(&n_n);
}

//fct to save the "text" in a file : output.txt
void final_nn(network n_n) 
{
    int exist=1;
    int i=0;
    //to erase the file if it already exist
    FILE *output=fopen("output.txt","w");
    fclose(output);
    while(exist==1)
    {
        FILE *output = fopen("output.txt", "a");
        char filename_format[] = "%d.txt";
        char filename[sizeof(filename_format) + 2];
        
        snprintf(filename, sizeof(filename), filename_format, i);
        FILE *fp = fopen(filename, "r");
        if(fp==NULL)
        {
            printf("there is no more letters (there should have %d letters in the output file)\n",i);
            exist=0;
        }
        if(exist==1)
        {
            int k=0;
            char ch;
            //for every char in the .txt
            while((ch=fgetc(fp))!=EOF)
            {
                
                if(ch!='\n')
                {
                    n_n.layer[0].neu[k].actv=ch-'0';
                    k++;
                }
                
            }
            forward(n_n);        
            for(int j=0;j<52;j++)
            {
                    
                if((int)round(n_n.layer[2].neu[j].actv)==1)
                {
                    if(j<26)
                    {
                        fprintf(output, "%c",(char)(j+65));

                    }
                    else
                    {
                        fprintf(output, "%c",(char)(j+71));
                    }
                }
            }  
            
        }
        fclose(output);
        if(exist==1)
        {
            fclose(fp);    
        }
        i++;
    }
    //when the test is over we free the allocated memory
    freeall(&n_n);
}
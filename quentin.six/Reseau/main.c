#include "backprop.h"
#include "layer.h"
#include "neural_network.h"
#include "neuron.h"
#include <time.h>
#include "networkSaver.h"
#include <stdlib.h>

//the main function
int main(void)
{
    srand(time(NULL));

    network n_n = create_neural_network(3,0.15,156);

    FILE *fPointer = fopen("weights.save","r");
    FILE *fBias = fopen("biases.save", "r");
    if (fPointer == NULL || fBias == NULL)
    {
        printf("--------------------Missing save file.--------------------\n");
        init_weights_biases(n_n, 0);
    }
    else
    {
        printf("--------------------Save files found.--------------------\n--------------------Loading files...---------------------\n");
        neuralLoad(n_n, fPointer, fBias);
        init_weights_biases(n_n, 1);
    }

    train_neural_net(n_n);

    neuralSave(n_n);

    test_nn(n_n);

    return 0;
}

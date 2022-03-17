#include "gtk.h"
#include "../Separation/segmentation.h"
#include "../Separation/extraction.h"
#include "../Init/chargnbimage.h"
#include "../Init/colorbw.h"


#include "../../Reseau/backprop.h"
#include "../../Reseau/layer.h"
#include "../../Reseau/neural_network.h"
#include "../../Reseau/neuron.h"
#include <time.h>
#include "../../Reseau/networkSaver.h"
#include <stdlib.h>

gchar *filename = "";
char *text = "";
GtkWidget *parent;

void load_image(GtkButton *button, GtkImage *image)
{
    if (strcmp(filename, "") == 0)
        return;
    (void)(button);
        SDL_Surface *img = IMG_Load((char *) filename);
        if(img->w > 600 && img->h > 500)
        {
            printf("Resize needed\n");
//            SDL_Surface *new = Resize(img, 0.5, 0.5);

//            SDL_SaveBMP(new, "image_resize");
//            gtk_image_set_from_file (GTK_IMAGE(image), "image_resize");
            gtk_image_set_from_file(GTK_IMAGE(image), filename);
        }
        else
        {
            gtk_image_set_from_file(GTK_IMAGE(image), filename);
        }
}


void save_text()
{
    int systemRC = system("rm [0-9]*.txt");
    if (systemRC == -1)
    {
        //To manage errors
    }
    
}






void open_file(GtkButton *button, GtkLabel *text_label)
{
    GtkWidget *label = (GtkWidget *) text_label;
    GtkWidget *toplevel = gtk_widget_get_toplevel(GTK_WIDGET(button));
    GtkWidget *dialog = gtk_file_chooser_dialog_new(("Choose image"),
    GTK_WINDOW(toplevel), GTK_FILE_CHOOSER_ACTION_OPEN, 
    "Open", GTK_RESPONSE_ACCEPT, "Cancel", GTK_RESPONSE_CANCEL, NULL);


    switch (gtk_dialog_run(GTK_DIALOG(dialog)))
    {
        case GTK_RESPONSE_ACCEPT:
        {
            filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            gtk_label_set_text(GTK_LABEL(label), filename);
            break;
        }
        default:
            break;
    
    }
    gtk_widget_destroy(dialog);


}

//fct to train the neuron network
void train()
{
    //create the structure filled with "nothing"
    network n_n = create_neural_network(3,0.15,156);
    FILE *fPointer = fopen("weights.save","r");
    FILE *fBias = fopen("biases.save", "r");
    if (fPointer == NULL || fBias == NULL)
    {
        //if doesn't exist we initialize them
        printf("--------------------Missing save file.--------------------\n");
        init_weights_biases(n_n, 0);
    }
    else
    {
        //if it exists we loard them
        printf("--------------------Save files found.--------------------\n--------------------Loading files...---------------------\n");
        neuralLoad(n_n, fPointer, fBias);
        init_weights_biases(n_n, 1);
    }
    printf("Training in process :\n");
    train_neural_net(n_n);
    neuralSave(n_n);
    //will take the training_set in exemple and print them in the console
    printf("These are the output for the training set :\n");
    test_nn(n_n);
}

//fct to delete .save files (the neural network)
void deletenn()
{

    int systemRet = system("rm *.save");
    if(systemRet == -1)
    {
        //just for handling the error/warning message     
    }

}


int OCR(GtkButton *button, GtkTextBuffer *buffer)
{
    if(strcmp(filename, "") == 0)
    {
        return 1;
    }
    (void)(button);
    SDL_Init(SDL_INIT_VIDEO);
    printf("Opening %s \n", filename);
    SDL_Surface *img = IMG_Load((char *) filename);
 
    grayscale(img);
    printf("gray\n");
    

    black_white(img);
    printf("Black and white \n");

    seg_hor(img);
    printf("segmented\n");
    
    //check if it exists
    network n_n = create_neural_network(3,0.15,156);
    FILE *fPointer = fopen("weights.save","r");
    FILE *fBias = fopen("biases.save", "r");
    if (fPointer == NULL || fBias == NULL)
    {
        //if doesn't exist we initialize them
        printf("--------------------Missing save file.--------------------\n");
        init_weights_biases(n_n, 0);
    }
    else
    {
        //if it exists we loard them
        printf("--------------------Save files found.--------------------\n--------------------Loading files...---------------------\n");
        neuralLoad(n_n, fPointer, fBias);
        init_weights_biases(n_n, 1);
    }
    //if it doesnt exist we save (if already exists doesn't change anything)
    neuralSave(n_n);
    //fct to save the outputs of the segmented image in a file : output.txt
    final_nn(n_n);

    (void)buffer;
    SDL_Quit();
    return (EXIT_SUCCESS);
}


void create_gtk(int argc, char **argv)
{
    GtkWidget *main_window;
    SGlobalData data;
    gtk_init(&argc, &argv);
    data.builder = gtk_builder_new();
    gtk_builder_add_from_file(data.builder, "main.glade", NULL);
    main_window = GTK_WIDGET(gtk_builder_get_object(data.builder, "main_window"));
    g_signal_connect(G_OBJECT(main_window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    parent = main_window;
    gtk_builder_connect_signals(data.builder, &data);
    gtk_window_set_title(GTK_WINDOW(main_window), "Ekip");
    gtk_widget_show_all(main_window);
    gtk_main();
}

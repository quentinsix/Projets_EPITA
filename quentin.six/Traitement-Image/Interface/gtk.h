#ifndef GTK_H
#define GTK_H
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>



typedef struct {
    GtkBuilder *builder;
    gpointer data;
}SGlobalData;


void load_image(GtkButton *button, GtkImage *image);
void save_text();
void open_file(GtkButton *button, GtkLabel *text_label);
void train();//Pour quintin
void deletenn();//Pour quintin, à ajouter dans le fichier .c
int OCR(GtkButton *button, GtkTextBuffer *buffer);
void create_gtk(int argc, char *argv[]);

#endif

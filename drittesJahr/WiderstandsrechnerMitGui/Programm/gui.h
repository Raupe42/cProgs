#include <gtk/gtk.h>
#include "Widerstandsrechner.h"
#define MAIN

typedef struct gui_struct
{
    GtkWidget* ring1_l;         //l (kleines L )- wie Label
    GtkWidget* ring2_l;
    GtkWidget* ring3_l;
    GtkWidget* ring4_l;
    GtkWidget* ring5_l;
    GtkWidget* ring6_l;         //NEU
    GtkWidget* t_frame;         //NEU
    GtkWidget* b_frame;         //NEU
    GtkWidget* l_frame;         //NEU
    GtkWidget* r_frame;         //NEU
    GtkWidget* output;
    GtkWidget *terminal;
    GtkWidget *scales[6];       //NEU angepasst
    int ringWerte[6];
} gui_t;

int main_gui(int argc, char *argv[]);
#include <gtk/gtk.h>
#include "Widerstandsrechner.h"
#define MAIN

typedef struct gui_struct
{
    GtkWidget* ring1_l;
    GtkWidget* ring2_l;
    GtkWidget* ring3_l;
    GtkWidget* ring4_l;
    GtkWidget* ring5_l;
    GtkWidget* output;
    GtkWidget *terminal;
    GtkWidget *scales[5];

} gui_t;

int main_gui(int argc, char *argv[]);
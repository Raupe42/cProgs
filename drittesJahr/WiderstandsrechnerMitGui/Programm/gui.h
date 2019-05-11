/*
author: Tim, Jens

Bereitstellen der globalen Daten für die GUI
*/


#include <gtk/gtk.h>
#include "Widerstandsrechner.h"
#define MAIN


//Struktur mit den wichtigen Bestandteilen der GUI
typedef struct gui_struct
{
    GtkWidget* ring1_l;         //l (kleines L )- wie Label
    GtkWidget* ring2_l;
    GtkWidget* ring3_l;
    GtkWidget* ring4_l;
    GtkWidget* ring5_l;
    GtkWidget* ring6_l;        
    GtkWidget* t_frame;         
    GtkWidget* b_frame;         
    GtkWidget* l_frame;         
    GtkWidget* r_frame;         
    GtkWidget* output;
    GtkWidget *terminal;
    GtkWidget *scales[6];       
    int ringWerte[6];
    GdkColor colors[13];       // = {0black, 1brown, 2red, 3orange, 4yellow, 5green, 6blue, 7violet, 8grey, 9white, 10gold, 11silver, 11none};
    GdkColor bg_colors[3];     // 0black,1 beige,2 lBlue
} gui_t;

//Hauptaufruf der grafischen Oberfläche
int main_gui(int argc, char *argv[]);

/*
Hauptprogramm des Widerstandsrechners mit GUI
Bedienkozepte:
- Kommandozeile der Gui funktioniert wie das Konsolenprogramm


*/
#include <string.h>
#include "Main.h"


#define MAIN_FUNK

//Proto
int init_gui (int argc, char *argv[], gui_t *p_gui);
//end_proto

int main (int argc, char *argv[])
{
    gui_t gui;
    if (!strcmp (argv [1], "-cmd"))
    {
        main_Konsole();
        return 42;
    }



    return 0;
}

int init_gui (int argc, char *argv[], gui_t *p_gui)
{
    GtkWidget *elem; //niemals elem trauen - ausser es wurde grade zugewiesen
    gtk_init(argc, argv);

    elem = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    p_gui->window = elem;
    
}
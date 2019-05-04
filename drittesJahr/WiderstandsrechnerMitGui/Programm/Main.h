#include "Widerstandsrechner.h"
#include <gtk/gtk.h>

typedef struct gui_strct
{
    GtkWidget *window;
    GtkWidget *labelUeberschrift;
    GtkWidget *entryKommandozeile;
}gui_t;
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

//Callbackfunktion als Antwort 
void aktion (GtkWidget* feld, gpointer gp)
{
    const char * str;
    str = gtk_entry_get_text (GTK_ENTRY(feld));
    printf ("%lf\n", atof(str));
    return;
}
//ende

//zum testen
int main (int argc, char *argv [])
{
    GtkWidget *fenster;
    GtkWidget *feld;
    gtk_init(&argc, &argv);
    fenster = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    feld = gtk_entry_new ();
    g_signal_connect(G_OBJECT(feld), "changed", G_CALLBACK(aktion), NULL);
    gtk_container_add(GTK_CONTAINER(fenster), feld);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
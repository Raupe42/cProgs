#include <gtk/gtk.h>

//Callbackfunktion als Antwort auf a
void aktion (GtkWidget* knopf, gpointer gp)
{
    g_print ("Fehler\n");
    return;
}
//ende von a

//abgeschrieben bzw um das fehlende erweitert
int main (int argc, char *argv [])
{
    char s[80]= "Tschuess";
    GtkWidget *fenster;
    GtkWidget *knopf;
    gtk_init(&argc, &argv);
    fenster = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    knopf = gtk_button_new_with_label ("Dies zu druecken waere ein Fehler");
    g_signal_connect(G_OBJECT(knopf), "clicked", G_CALLBACK(aktion), s);
    gtk_container_add(GTK_CONTAINER(fenster), knopf);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
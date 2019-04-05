#include <gtk/gtk.h>


gboolean fertig (gpointer daten)
{
    static int anzahl = 0;
    ++anzahl;
    g_print ("&i mal aufgerufen\n", anzahl);
    if (anzahl == 11)
        return FALSE;
    else 
        return TRUE;
}

int main (int argc, char * argv[])
{
    GtkWidget *fenster;
    gtk_init (argc, argv);
    fenster = gtk_window_new(GTK_WINDOW_TOPLEVEL);  //was macht das?
    g_signal_connect (G_OBJECT(fenster), "delete-event", gtk_main_quit, NULL);
    g_timeout_add (1000, fertig, NULL);

    gtk_widget_show_all (fenster);
    gtk_main ();
    return 0;
}
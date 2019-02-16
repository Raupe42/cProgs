#include <gtk/gtk.h>
  GtkWidget *etikett;
//gpointer: zu beeinflussendes Objekt
gboolean einfunk (GtkWidget *fenster, GdkEvent ereignis, gpointer m)
{
    gtk_label_set_text(GTK_LABEL(etikett), "In Konsole Strg-C tippen.");
    return TRUE;
}


int main (int argc, char *argv[])
{
    GtkWidget *fenster;
  

    gtk_init(&argc, &argv);
    fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    etikett = gtk_label_new ("Hallo Welt\n beliebiger Text\ngenug gelesen\nFENSTER SCHLIESSEN");
    gtk_container_add (GTK_CONTAINER(fenster), etikett);
    g_signal_connect(G_OBJECT(fenster), "delete-event", G_CALLBACK(einfunk), NULL);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
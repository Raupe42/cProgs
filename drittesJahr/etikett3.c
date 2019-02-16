#include <gtk/gtk.h>
#include <string.h>
  GtkWidget *etikett;
 int anzahl = 1;
//gpointer: zu beeinflussendes Objekt
gboolean einfunk (GtkWidget *fenster, GdkEvent ereignis, gpointer m)
{
    char str [80];
    sprintf (str, "schon %i mal geschlossen", anzahl);
    anzahl ++;
    gtk_label_set_text(GTK_LABEL(etikett), str);
    if (anzahl > 10)
    {
         gtk_label_set_text(GTK_LABEL(etikett), "fertig");
         gtk_main_quit();
    }
    
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
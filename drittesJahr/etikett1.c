#include <gtk/gtk.h>
int main (int argc, char *argv[])
{
    GtkWidget *fenster;
    GtkWidget *etikett;

    gtk_init(&argc, &argv);
    fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    etikett = gtk_label_new ("Hallo Welt\n beliebiger Text");
    gtk_container_add (GTK_CONTAINER(fenster), etikett);
    g_signal_connect(G_OBJECT(fenster), "delete-event", gtk_main_quit, NULL);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
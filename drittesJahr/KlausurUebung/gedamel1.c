#include <gtk/gtk.h>

//Callback funktionen
gboolean exitOnClose (GtkWidget *fenster, GdkEvent ev, gpointer data)
{
    gtk_main_quit();
    return TRUE;
}


int main (int argc, char * argv [])
{
    //Vars
    GtkWidget *fenster;
    GtkWidget *vBox;
    GtkWidget *ueberschrift;
    GtkWidget *canvas;
    //Init
    gtk_init(&argc, &argv);

    //Objekte
    fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    vBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 1);
    ueberschrift = gtk_label_new ("Ueberschrift!");
    canvas = gtk_drawing_area_new ();
    //Box packen
    gtk_box_pack_start (GTK_BOX(vBox), ueberschrift, !0, !0, 1);
    gtk_box_pack_end (GTK_BOX(vBox), canvas, !0, !0, 1);
    //Signale
    g_signal_connect (G_OBJECT(fenster), "delete-event",G_CALLBACK(exitOnClose), NULL);
    
    //main
    gtk_container_add (GTK_CONTAINER(fenster), vBox);
    gtk_widget_show_all (fenster);
    gtk_main();
}
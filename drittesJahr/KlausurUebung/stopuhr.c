#include <gtk/gtk.h>

struct etwasGui {
    GtkWidget *etikettRemainTime;
    GtkWidget *entryStartwert;
    guint timerAnzeige;
    int verbleibendeSekunden;
};

gboolean exitOnClose (GtkWidget *fenster, GdkEvent ev, gpointer gp)
{
    gtk_main_quit();
    return TRUE;
}



gboolean repaint (gpointer gp)
{
    struct etwasGui *gui = gp;
    char buffer [20];
    //g_print ("tick\n");
    //gtk_label_set_text (GTK_LABEL(gui.etikettRemainTime), sprintf ("%i", g_timeout_ gui.timer)
    // das geht so nicht - ein Timer kann anscheinend nicht nach seinem wert gefragt werden
    gui->verbleibendeSekunden --;

    //gtk_label_set_text (GTK_LABEL (gui->etikettRemainTime), sprintf ("%i", gui->verbleibendeSekunden));
    sprintf (buffer, "%i", gui->verbleibendeSekunden);
    gtk_label_set_text (GTK_LABEL (gui->etikettRemainTime), buffer);
    //gtk_label_set_text (GTK_LABEL (gui->etikettRemainTime), "9");
    //g_print ("tok\n");
    if (!(gui->verbleibendeSekunden))
        gtk_main_quit();
    return TRUE;
}

void start (GtkWidget *buttonStart, gpointer gp)
{
    struct etwasGui *gui = gp;
    char buffer [20];
    gui->verbleibendeSekunden = atoi (gtk_entry_get_text (gui->entryStartwert));
    //    gtk_label_set_text (GTK_LABEL (gui->etikettRemainTime), "a");
    sprintf (buffer, "%i", gui->verbleibendeSekunden);
    gtk_label_set_text (GTK_LABEL (gui->etikettRemainTime), buffer);
//dummy timer für aktualisierung der anzeige
   gui->timerAnzeige = g_timeout_add (1000, (repaint), gui);
}

int main (int argc, char *argv[])
{
    GtkWidget *fenster;
    GtkWidget *vBox;
    GtkWidget *etikettRemainTime;
    GtkWidget *buttonStart;
    GtkWidget *entryStartwert;
    struct etwasGui gui;
    gtk_init(&argc, &argv);

    fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    vBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 2);
    etikettRemainTime = gtk_label_new ("zeit");
    buttonStart = gtk_button_new_with_label ("start");
    entryStartwert = gtk_entry_new ();
    
    gtk_box_pack_start (GTK_BOX (vBox), entryStartwert, TRUE, TRUE, 2);
    gtk_box_pack_start (GTK_BOX (vBox), buttonStart, TRUE, TRUE, 4);
    gtk_box_pack_start (GTK_BOX (vBox), etikettRemainTime, TRUE, TRUE, 2);

    gui.entryStartwert = entryStartwert;
    gui.etikettRemainTime = etikettRemainTime;


    g_signal_connect (G_OBJECT (fenster), "delete-event", G_CALLBACK (exitOnClose), NULL);
    g_signal_connect (G_OBJECT (buttonStart), "clicked", G_CALLBACK (start), &gui);


    gtk_container_add (GTK_CONTAINER (fenster), vBox);
    gtk_widget_show_all (fenster);
    gtk_main();
    return 0;


}
#include <gtk/gtk.h>
//um das fehlende erweitert
int main (int argc, char *argv [])
{
    GtkWidget *fenster;
    GtkWidget *feld;
    GtkWidget *knopf;
    GtkWidget *schachtel;
    gtk_init(&argc, &argv);
    fenster = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    schachtel = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 2);
    feld = gtk_entry_new ();
    knopf = gtk_button_new_with_label ("Nicht fuer mich lesbar");
    gtk_box_pack_start (GTK_BOX(schachtel), feld, TRUE, TRUE, 2);
    gtk_box_pack_start (GTK_BOX(schachtel), knopf, TRUE, TRUE, 2);
    gtk_container_add(GTK_CONTAINER(fenster), schachtel);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
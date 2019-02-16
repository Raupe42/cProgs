#include <gtk/gtk.h>
#include <time.h>
  GtkWidget *etikett;
//gpointer: zu beeinflussendes Objekt
gboolean einfunk (GtkWidget *fenster, GdkEvent ereignis, gpointer m)
{
    //gtk_label_set_text(GTK_LABEL(etikett), "In Konsole Strg-C tippen.");
    gtk_main_quit();
    return TRUE;
}

void knopfKlick (GtkWidget *knopf, gpointer muell)
{
//g_print("Text");

    time_t t;   //Zeit in sekunden seit 1.1.1970
    struct tm tRec; //Zeit als Record
//printf ("%i\n",sizeof(tRec));
    t = time (NULL);
    //printf("%i\n", t);

    tRec = *localtime(&t);
    //g_print("%02i.%02i.%04i\n", tRec.tm_mday, tRec.tm_mon + 1, tRec.tm_year + 1900);
    g_print ("%02i:%02i:%02i\n", tRec.tm_hour, tRec.tm_min, tRec.tm_sec);
}

int main (int argc, char *argv[])
{
    GtkWidget *fenster;
    GtkWidget *knopf;

    gtk_init(&argc, &argv);
    fenster = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    knopf = gtk_button_new_with_label("Uhrzeit");
   // etikett = gtk_label_new ("Hallo Welt\n beliebiger Text\ngenug gelesen\nFENSTER SCHLIESSEN");
   // gtk_container_add (GTK_CONTAINER(fenster), etikett);
   gtk_container_add (GTK_CONTAINER(fenster), knopf);
    g_signal_connect(G_OBJECT(fenster), "delete-event", G_CALLBACK(einfunk), NULL);
     g_signal_connect(G_OBJECT(knopf), "clicked", G_CALLBACK(knopfKlick), NULL);
    gtk_widget_show_all(fenster);
    gtk_main();
    return 0;
}
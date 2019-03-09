#include <gtk/gtk.h>
#include "builder1.h"
void knopfgeklickt(GtkWidget *knopf, gpointer daten)
{
  GtkBuilder *baum=daten;
  GObject *element=gtk_builder_get_object(baum, "etikett");
  gtk_label_set_text(GTK_LABEL(element), "Hallo!");
}

int main(int argc, char *argv[])
{
  GtkBuilder *baum;
  GObject *element;
  GError *fehler=NULL;
  gtk_init(&argc, &argv);

  baum=gtk_builder_new();                     
  gtk_builder_add_from_string(baum, ui_string, -1, &fehler); 
  /*if(fehler)
  { 
     g_print("%s\n", fehler->message); 
     return 1;
  }*/
  
  element=gtk_builder_get_object(baum, "fenster");
  g_signal_connect(element, "delete_event", 
                   gtk_main_quit, NULL);

  element=gtk_builder_get_object(baum, "knopf");
  g_signal_connect(element, "clicked", 
                   G_CALLBACK(knopfgeklickt), baum);

  element=gtk_builder_get_object(baum, "fenster");
  gtk_widget_show_all(GTK_WIDGET(element));
  gtk_main();
  return 0;
}

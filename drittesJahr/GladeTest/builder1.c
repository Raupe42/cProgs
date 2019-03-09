#include <gtk/gtk.h>
void knopfgeklickt(GtkWidget *knopf, gpointer muell)
{
  g_print("Hallo!\n");
}

int main(int argc, char *argv[])
{
  GtkBuilder *baum;
  GObject *element;

  gtk_init(&argc, &argv);

  baum=gtk_builder_new();                     
  gtk_builder_add_from_file(baum, "builder1.ui", NULL); 

  element=gtk_builder_get_object(baum, "fenster");
  g_signal_connect(element, "delete_event", 
                   gtk_main_quit, NULL);

  element=gtk_builder_get_object(baum, "knopf");
  g_signal_connect(element, "clicked", 
                   G_CALLBACK(knopfgeklickt), NULL);

  element=gtk_builder_get_object(baum, "fenster");
  gtk_widget_show_all(GTK_WIDGET(element));
  gtk_main();
  return 0;
}

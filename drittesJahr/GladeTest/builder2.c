#include <gtk/gtk.h>

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

  gtk_init(&argc, &argv);

  baum=gtk_builder_new();                     
  gtk_builder_add_from_file(baum, "builder2.ui", NULL); 
  gtk_builder_connect_signals(baum, baum); /* 2. Parameter: daten */

  element=gtk_builder_get_object(baum, "fenster");
  gtk_widget_show_all(GTK_WIDGET(element));
  gtk_main();
  return 0;
}

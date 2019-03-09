#include <gtk/gtk.h>

typedef struct gui_struct {
  GtkBuilder* tree;
  GtkWidget* window1;
  GtkWidget* button1;
  GtkWidget* switch1;
  GtkWidget* progBar;
}gui_t;


void knopfgeklickt(GtkWidget *knopf, gpointer pointer)
{
  gui_t* p_gui = pointer;
  if (gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(p_gui->progBar))> 0.9)
    gtk_main_quit();
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(p_gui->switch1)))
    gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(p_gui->progBar),
           gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(p_gui->progBar))  + 0.1);
  //gtk_progress_bar_pulse (GTK_PROGRESS_BAR(p_gui->progBar));
  g_print("Klick %g\n", gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(p_gui->progBar)));
}
void schalterGeklickt(GtkToggleButton *schalter, gpointer pointer)
{
  gui_t* p_gui = pointer;
  g_print("%d\n", gtk_toggle_button_get_active(schalter));  //1 an 0 aus
  //if (gtk_toggle_button_get_active(schalter))
    //gtk_progress_bar_pulse (GTK_PROGRESS_BAR(p_gui->progBar));
  //gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(p_gui->progBar),
    //       gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(p_gui->progBar))  + 0.1);
  //g_print("Klick %g\n", gtk_progress_bar_get_fraction (GTK_PROGRESS_BAR(p_gui->progBar)));
}



int main(int argc, char *argv[])
{
  GtkBuilder *baum;
  GObject *element;
  gui_t gui;

  gui.tree = baum;
  gtk_init(&argc, &argv);

  baum=gtk_builder_new();                     
  gtk_builder_add_from_file(baum, "eigenesUI.ui", NULL); 

  element=gtk_builder_get_object(baum, "window1");
  g_signal_connect(element, "delete_event", 
                   gtk_main_quit, NULL);
  gui.window1 = GTK_WIDGET(element);

  element=gtk_builder_get_object(baum, "button1");
  g_signal_connect(element, "clicked", 
                   G_CALLBACK(knopfgeklickt), &gui);
  gui.button1 = GTK_WIDGET(element);

  element=gtk_builder_get_object(baum, "togglebutton1");
  g_signal_connect(element, "toggled", G_CALLBACK(schalterGeklickt), &gui);
  gui.switch1 = GTK_WIDGET(element);

  element = gtk_builder_get_object(baum, "progressbar1");
  gui.progBar = GTK_WIDGET(element);

  element=gtk_builder_get_object(baum, "window1");
  gtk_widget_show_all(GTK_WIDGET(element));
  gtk_main();
  return 0;
}

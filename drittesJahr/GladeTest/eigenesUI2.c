#include <gtk/gtk.h>

typedef struct gui_struct {
  GtkBuilder* tree;
  GtkWidget* window1;
  GtkWidget* button1;
  GtkWidget* switch1;
  GtkWidget* progBar;
  GtkWidget* drawArea1;
  GtkWidget* drawArea2;
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

gboolean zeichnen0 (GtkWidget *flaeche, cairo_t *cr, gpointer muell)
{
    cairo_move_to (cr, 0, 0);
    cairo_line_to(cr, 400, 400);
    cairo_move_to (cr, 0, 400);
    cairo_line_to (cr, 400, 0);
    cairo_stroke(cr); //zeichnen
    return FALSE;
}

gboolean zeichnen1 (GtkWidget *flaeche, cairo_t *cr, gui_t gui)
{
  guint breite, hoehe;
  breite = gtk_widget_get_allocated_width (flaeche);
  hoehe = gtk_widget_get_allocated_height (flaeche);
   cairo_move_to (cr, 0, 0);
    cairo_line_to(cr, breite, hoehe);
    cairo_move_to (cr, 0, hoehe);
    cairo_line_to (cr, breite, 0);
    cairo_stroke(cr); //zeichnen
}

int main(int argc, char *argv[])
{
  GtkBuilder *baum;
  GObject *element;
  gui_t gui;

  gui.tree = baum;
  gtk_init(&argc, &argv);

  baum=gtk_builder_new();                     
  gtk_builder_add_from_file(baum, "eigenesUI2.ui", NULL); 

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

  element = gtk_builder_get_object(baum, "drawingarea1");
  gui.drawArea1 = GTK_WIDGET (element);
  gui.drawArea2 = gtk_builder_get_object(baum, "drawingarea2");

  g_signal_connect(G_OBJECT (element), "draw", G_CALLBACK(zeichnen0), NULL);
  g_signal_connect(G_OBJECT(gui.drawArea2), "draw", G_CALLBACK(zeichnen1), &gui);
  element=gtk_builder_get_object(baum, "window1");
  //gtk_window_maximize(GTK_WINDOW(element));
  gtk_widget_show_all(GTK_WIDGET(element));
  gtk_main();
  return 0;
}

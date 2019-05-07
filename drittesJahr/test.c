#include <gtk/gtk.h>

struct ringe_t {
GtkWidget *combo;

GtkWidget *labelFuerErg;
};

//void erg(GtkWidget *widget,gpointer nix)
void erg(GtkWidget *widget,struct ringe_t *nix)
{
  //gtk_label_set_text(GTK_LABEL(nix->labelFuerErg),"Hier das Ergebnis!");
  g_print("hier kommt was rein\n");
  g_print("%s",gtk_combo_box_text_get_active_text (nix->combo));
                                        // hier KEIN *
}

void combo_selected(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

void combo_selected2(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

void combo_selected3(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

void combo_selected4(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

void combo_selected5(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

void combo_selected6(GtkWidget *widget, gpointer window) 
{
  gchar *text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(widget));
 // gtk_label_set_text(GTK_LABEL(window), text);
  g_print("%s\n",(GTK_LABEL(window), text));
  g_free(text);
}

int main(int argc, char *argv[]) {
  GtkWidget *window;
  GtkWidget *hbox;
  GtkWidget *vbox, *vbox2, *vbox3, *vbox4, *vbox5, *vbox6;
  GtkWidget *combo, *combo2, *combo3, *combo4, *combo5, *combo6;
  GtkWidget *label, *label2, *label3, *label4, *label5, *label6, *label7,*label8,*label9,*label10,*label11;
  GtkWidget *button;
  gtk_init(&argc, &argv);

  struct ringe_t ringe;
 
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Widerstandsrechner");
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);
  
  hbox = gtk_hbox_new(FALSE, 0);
  vbox = gtk_vbox_new(FALSE, 15);
  vbox2 = gtk_vbox_new(FALSE, 15);
  vbox3 = gtk_vbox_new(FALSE, 15);
  vbox4 = gtk_vbox_new(FALSE, 15);
  vbox5 = gtk_vbox_new(FALSE, 15);
  vbox6= gtk_vbox_new(FALSE, 15);

  //combo = gtk_combo_box_new_text();
  combo = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Orange");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Gelb");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Violett");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Grau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo), "Weiss");

  ringe.combo= combo;

  gtk_box_pack_start(GTK_BOX(vbox), combo, FALSE, FALSE, 0);
  label = gtk_label_new("1. Ring");
  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
  
  button = gtk_button_new_with_label("Berechnen!");
  //g_signal_connect(button,"clicked",G_CALLBACK(erg),(gpointer) label11);
 // label8 = gtk_label_new("Ergebnis");
  gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 35);

  gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(combo), "changed", 
        G_CALLBACK(combo_selected), (gpointer) label);

  //combo2 = gtk_combo_box_new_text();
  combo2 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Schwarz");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Orange");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Gelb");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Violett");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Grau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo2), "Weiss");

  gtk_box_pack_start(GTK_BOX(vbox2), combo2, FALSE, FALSE, 0);
  label2 = gtk_label_new("2. Ring");
  gtk_box_pack_start(GTK_BOX(vbox2), label2, FALSE, FALSE, 0);

/* label9 = gtk_label_new("Ergebnis:");
  gtk_box_pack_start(GTK_BOX(vbox2), label9, FALSE, FALSE, 35);
*/
  gtk_box_pack_start(GTK_BOX(hbox), vbox2, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(combo2), "changed", 
        G_CALLBACK(combo_selected2), (gpointer) label2);

  //combo3 = gtk_combo_box_new_text();
  combo3 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Schwarz");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Orange");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Gelb");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Violett");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Grau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo3), "Weiss");

  gtk_box_pack_start(GTK_BOX(vbox3), combo3, FALSE, FALSE, 0);
  label3 = gtk_label_new("3. Ring");
  gtk_box_pack_start(GTK_BOX(vbox3), label3, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), vbox3, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(combo3), "changed", 
        G_CALLBACK(combo_selected3), (gpointer) label3);

//combo4 = gtk_combo_box_new_text();
 combo4 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Silber");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Gold");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Schwarz");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Orange");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Gelb");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo4), "Violett");


  gtk_box_pack_start(GTK_BOX(vbox4), combo4, FALSE, FALSE, 0);
  label4 = gtk_label_new("4. Ring");
  gtk_box_pack_start(GTK_BOX(vbox4), label4, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), vbox4, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(combo4), "changed", 
        G_CALLBACK(combo_selected4), (gpointer) label4);

 // combo5 = gtk_combo_box_new_text();
  combo5 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Fehlt");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Silber");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Gold");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo5), "Violett");


  gtk_box_pack_start(GTK_BOX(vbox5), combo5, FALSE, FALSE, 0);
  label5 = gtk_label_new("5. Ring");
  gtk_box_pack_start(GTK_BOX(vbox5), label5, FALSE, FALSE, 0);

 label10 = gtk_label_new("Ergebnis:");
  gtk_box_pack_start(GTK_BOX(vbox5), label10, FALSE, FALSE, 35);

  gtk_box_pack_start(GTK_BOX(hbox), vbox5, FALSE, FALSE, 0);
  g_signal_connect(G_OBJECT(combo5), "changed", 
        G_CALLBACK(combo_selected5), (gpointer) label5);

  //combo6 = gtk_combo_box_new_text();
  combo6 = gtk_combo_box_text_new();
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Fehlt");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Schwarz");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Braun");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Rot");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Orange");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Gelb");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Grün");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Blau");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Violett");
  gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo6), "Grau");

  gtk_box_pack_start(GTK_BOX(vbox6), combo6, FALSE, FALSE, 0);
  label6 = gtk_label_new("6. Ring");
  gtk_box_pack_start(GTK_BOX(vbox6), label6, FALSE, FALSE, 0);

 label11 = gtk_label_new("???");
  gtk_box_pack_start(GTK_BOX(vbox6), label11, FALSE, FALSE, 35);

  gtk_box_pack_start(GTK_BOX(hbox), vbox6, FALSE, FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), hbox);
  g_signal_connect(G_OBJECT(combo6), "changed", 
        G_CALLBACK(combo_selected6), (gpointer) label6);

g_signal_connect(button,"clicked",G_CALLBACK(erg), &ringe);
 /*
 label7 = gtk_label_new("Ergebnis");
  gtk_box_pack_start(GTK_BOX(hbox), label7, FALSE, FALSE, 0);(gpointer)
*/
  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);



  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
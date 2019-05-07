#include <gtk/gtk.h>
#include <string.h>

struct gui_t
{
    GtkWidget* ring1_l;
    GtkWidget* ring2_l;
    GtkWidget* ring3_l;
    GtkWidget* ring4_l;
    GtkWidget* ring5_l;
};

void terminal(GtkWidget *entry, gpointer muell)
{
    const char *p;
    p=gtk_entry_get_text(GTK_ENTRY(entry));
    g_print("Eingabe: %s \n", p);
}

void slider(GtkWidget *scale, gpointer daten)
{
    //Farbzuweisung
    GdkColor black, brown, red, orange, yellow, green, blue, violet, grey, white, gold, silver, none, temp;
   
    GdkColor *colors[] = {&black, &brown, &red, &orange, &yellow, &green, &blue, &violet, &grey, &white, &gold, &silver, &none};

    gdk_color_parse("#000000", &black);
    gdk_color_parse("#8B4513", &brown);
    gdk_color_parse("#FF0000", &red);
    gdk_color_parse("#FFA500", &orange);
    gdk_color_parse("#FFFF00", &yellow);
    gdk_color_parse("#00FF00", &green);
    gdk_color_parse("#0000FF", &blue);
    gdk_color_parse("#8A2BE2", &violet);
    gdk_color_parse("#BEBEBE", &grey);
    gdk_color_parse("#FFFFFF", &white);
    gdk_color_parse("#FFd700", &gold);
    gdk_color_parse("#C0C0C0", &silver);
    gdk_color_parse("#F0F0F0", &none);              //so etwa normal?




    struct gui_t *pgui;
    int wert;
    pgui=daten;
    const char *p=gtk_widget_get_name(scale);
    wert=gtk_range_get_value(GTK_RANGE(scale));
    g_print("Neuer Wert: %i \n", wert);             //Debug
    g_print("%s \n", p);                            //Debug
   /*
    switch (wert)
    {
        case 0:
            temp=black;break;
        case 1:
            temp=brown;break;
        case 2:
            temp=red;break;
        case 3:
            temp=orange;break;
        case 4:
            temp=yellow;break;
        case 5:
            temp=green;break;
        case 6:
            temp=blue;break;
        case 7:
            temp=violet;break;
        case 8:
            temp=grey;break;
        case 9:
            temp=white;break;
        case 10:
            temp=gold;break;
        case 11:
            temp=silver;break;
        case 12:
            temp=none;break;
        default:
            break;
    }
    */
    temp = *colors[wert];
    if(strcmp(p, "ring1")==0)
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring1_l), GTK_STATE_NORMAL, &temp);
    if(strcmp(p, "ring2")==0)
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring2_l), GTK_STATE_NORMAL, &temp);
    if(strcmp(p, "ring3")==0)
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring3_l), GTK_STATE_NORMAL, &temp);
    if(strcmp(p, "ring4")==0)
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring4_l), GTK_STATE_NORMAL, &temp);
    if(strcmp(p, "ring5")==0)
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring5_l), GTK_STATE_NORMAL, &temp);

    auswerten(pgui);
}

int main(int argc, char* argv[])
{
    struct gui_t gui;
    GtkWidget* fenster;
    GtkWidget *ring1_s;
    GtkWidget *ring2_s;
    GtkWidget *ring3_s;
    GtkWidget *ring4_s;
    GtkWidget *ring5_s;
    GtkWidget *heading;
    GtkWidget *entry;
    GtkWidget *v_box;
    GtkWidget *h_box;
    gtk_init(&argc, &argv);

    fenster=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    v_box=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    h_box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    heading=gtk_label_new("<big>Wiederstandsrechner</big>");
    gtk_label_set_use_markup(GTK_LABEL(heading),TRUE);

    gui.ring1_l=gtk_label_new("");
    ring1_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring1_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_widget_set_name(ring1_s, "ring1");
    gui.ring2_l=gtk_label_new("");
    ring2_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring2_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_widget_set_name(ring2_s, "ring2");
    gui.ring3_l=gtk_label_new("");
    ring3_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring3_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_widget_set_name(ring3_s, "ring3");
    gui.ring4_l=gtk_label_new("");
    ring4_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring4_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_widget_set_name(ring4_s, "ring4");
    gui.ring5_l=gtk_label_new("");
    ring5_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring5_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_widget_set_name(ring5_s, "ring5");

    entry=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(entry), 20);                             //reicht 20?
    gtk_entry_set_text(GTK_ENTRY(entry), "Terminal");

    gtk_window_set_default_size(GTK_WINDOW(fenster), 500, 200);                 //Defaultgröße des Fensters: Breite, Höhe

    gtk_container_add(GTK_CONTAINER(fenster), v_box);
    gtk_box_pack_start(GTK_BOX(v_box), heading, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(v_box), h_box, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(h_box), gui.ring1_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), ring1_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), gui.ring2_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), ring2_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), gui.ring3_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), ring3_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), gui.ring4_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), ring4_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), gui.ring5_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_box), ring5_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(v_box), entry, FALSE, FALSE, 2);

    g_signal_connect(G_OBJECT(ring1_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring2_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring3_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring4_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring5_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(terminal), NULL);          //ENTER-Taste zum "aktivieren"
    g_signal_connect(G_OBJECT(fenster), "delete-event", gtk_main_quit, NULL);
    
    gtk_widget_show_all(fenster);
    gtk_main();
}

void auswerten (struct gui_t* pgui)
{
    
}
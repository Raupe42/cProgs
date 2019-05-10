#include <gtk/gtk.h>
#include <string.h>

#include "gui.h"

void fuelleTerminal(gui_t *pgui);
void berechnen(gui_t *pgui);

void slider(GtkWidget *scale, gpointer daten)
{
    GdkColor temp;
    //Farbzuweisung
    /*
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
    gdk_color_parse("#D4AF37", &gold);
    gdk_color_parse("#C0C0C0", &silver);
    gdk_color_parse("#F0F0F0", &none);              //so etwa normal?
    */

    gui_t *pgui;
    int wert;
    pgui=daten;
    const char *p=gtk_widget_get_name(scale);
    wert=gtk_range_get_value(GTK_RANGE(scale));
    g_print("Neuer Wert: %i \n", wert);             //Debug
    g_print("%s \n", p);                            //Debug

    //temp = *colors[wert];
    temp = pgui->colors[wert];
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
    if(strcmp(p, "ring6")==0)                                                           //NEU
        gtk_widget_modify_bg(GTK_WIDGET(pgui->ring6_l), GTK_STATE_NORMAL, &temp);       //NEU

    fuelleTerminal(pgui);
    berechnen(pgui);
}

void terminal(GtkWidget *entry, gui_t *pgui)
{
    const char *p;
    char buffer[MAXINPUT];
    int i;
    p=gtk_entry_get_text(GTK_ENTRY(entry));
    strcpy(buffer, p);
    g_print("Eingabe: %s \n", p);
    berechnen(pgui);
    
    gtk_entry_set_text(GTK_ENTRY(entry), buffer);

    gtk_widget_modify_bg (pgui->ring1_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[0]]);
    gtk_widget_modify_bg (pgui->ring2_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[1]]);
    gtk_widget_modify_bg (pgui->ring3_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[2]]);
    gtk_widget_modify_bg (pgui->ring4_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[3]]);
    gtk_widget_modify_bg (pgui->ring5_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[4]]);
    gtk_widget_modify_bg (pgui->ring6_l, GTK_STATE_NORMAL, &pgui->colors[ pgui->ringWerte[5]]);
   
    printf("\n-%i-\n", pgui->ringWerte[5]);
}

void help(GtkWidget *button, gpointer muell)
{
    GtkWidget* help_window;
    GtkWidget* label;
    char buff [5000] = "";

    help_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(help_window), 600, 300);                 //Defaultgröße des Fensters: Breite, Höhe
    gtk_window_set_title(GTK_WINDOW(help_window), "Hilfe");
    //label=gtk_label_new("H\nI\nL\nF\nE\n!");

    strcat (buff, "<big>Widerstandsrechner V2.0\nDie Farben des Widerstandes an den Schiebereglern einstellen.\n");
    strcat (buff, "Das Ergebnis wird in unterschalb der Schieberegler angezeigt.\n");
    strcat (buff, "\nAlternativ kann das Programm auch über die Konsole bedient werden.\n");
    strcat (buff, "Das Terminal wird wie die Grundversion (Konsolenanwendung) bedient.\n");
    strcat (buff, "In die Terminal-Zeile die Farben (kürzel) eingeben und mit Enter akzeptieren.\n");
    strcat (buff, "Es gelten weiterhin die deutschen und englischen Kurzzeichen der Farben.\n");
    strcat (buff, "\n Special: Aufrufparameter \n-? oder -help : Anzeige der Hilfe\n");
    strcat(buff, "-cmd : Aufrufen des Originalprogramms \"Widerstandsrechner\"\n");
    strcat (buff, "</big>");

    label=gtk_label_new("");
    
    gtk_label_set_text (GTK_LABEL(label), buff);
    gtk_label_set_use_markup (GTK_LABEL(label), TRUE);
    gtk_container_add(GTK_CONTAINER(help_window), label);
    gtk_widget_show_all(help_window);
}

void fuelleTerminal (gui_t* pgui)
{
    int i, i_wert, next_wert, ringzahl = 1;
    GdkColor *tmpColor;
    gdouble wert;
    char str[80] = "";
    char colorStr[13][5] = {"bk", "bn", "rd", "or", "ye", "gn", "bl", "vio", "gy", "wh", "au", "ag", ""};
   
    
     for (i = 0; i < 6; i++)
    {
         wert = gtk_range_get_value(GTK_RANGE(pgui->scales[i]));
         i_wert = wert;
         if (i < 5)
            next_wert = gtk_range_get_value(GTK_RANGE(pgui->scales[i+1]));
        // if (wert < 13)
        if (i == 0 && i_wert == 12)
        {
            i_wert = 11;
        }
        if (strcmp ("", colorStr [i_wert]))
            strcat(str, colorStr [i_wert]);
        if (i < 5)
        {
            //printf ("%i", next_wert);
            if (strcmp ("", colorStr [next_wert]))
            {
                strcat(str, "-");
                ringzahl++;
            }
        }
    }
    
    gtk_entry_set_text(GTK_ENTRY(pgui->terminal), str);

    
    return; 
}

int main_gui(int argc, char* argv[])
{
    int i;
    gui_t gui;
    GtkWidget* fenster;
    GtkWidget *ring1_s;     //s wie scale
    GtkWidget *ring2_s;
    GtkWidget *ring3_s;
    GtkWidget *ring4_s;
    GtkWidget *ring5_s;
    GtkWidget *ring6_s;             //NEU
    GtkWidget *heading;
    GtkWidget *entry;
    GtkWidget *b_help;
    GtkWidget *v_box;
    GtkWidget *h_box;
    GtkWidget *h_box2;
    GtkWidget *v_leg1;
    GtkWidget *v_leg2;
    GtkWidget *empty1;
    GtkWidget *empty2;
    GtkWidget *empty3;
    GtkWidget *empty4;
    GtkWidget *leg1;
    GtkWidget *leg2;
    GtkWidget *v_frame;         //NEU
    GtkWidget *h_scale;         //NEU

    /*
    GdkColor black, beige, lBlue;                  //NEU angepasst
    gdk_color_parse("#000000", &black);
    gdk_color_parse("#E1C699", &beige);             //NEU
    gdk_color_parse("#00BFFF", &lBlue);            //NEU
*/
    GdkColor *tmpColor;
    gtk_init(&argc, &argv);
    initColors(&gui);

    fenster=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    v_box=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    h_box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);               //NEU angepasst
    heading=gtk_label_new("<big>Widerstandsrechner</big>");
    gtk_label_set_use_markup(GTK_LABEL(heading),TRUE);

    v_leg1=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    v_leg2=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    empty1=gtk_label_new("");
    empty2=gtk_label_new("");
    empty3=gtk_label_new("");
    empty4=gtk_label_new("");
    leg1=gtk_label_new("");
    leg2=gtk_label_new("");

    gtk_widget_modify_bg(GTK_WIDGET(leg1), GTK_STATE_NORMAL, &gui.bg_colors[0]);
    gtk_widget_modify_bg(GTK_WIDGET(leg2), GTK_STATE_NORMAL, &gui.bg_colors[0]);
    gtk_widget_set_size_request(leg1, 40, 5);                                   //NEU angepasst
    gtk_widget_set_size_request(leg2, 40, 5);                                   //NEU angepasst

    //NEU

    v_frame=gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gui.t_frame=gtk_label_new("");
    gui.b_frame=gtk_label_new("");
    gui.l_frame=gtk_label_new("");
    gui.r_frame=gtk_label_new("");

    if (FALSE)           //if "Metallschicht"
    {
        tmpColor = &gui.bg_colors[2];    //hellblau
        gtk_widget_modify_bg(GTK_WIDGET(gui.t_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.b_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.l_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.r_frame), GTK_STATE_NORMAL, tmpColor);
    }
    else
    {
        tmpColor = &gui.bg_colors[1];    //beige
        gtk_widget_modify_bg(GTK_WIDGET(gui.t_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.b_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.l_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(gui.r_frame), GTK_STATE_NORMAL, tmpColor);
    }
    
    gtk_widget_set_size_request(gui.t_frame, -1, 5);
    gtk_widget_set_size_request(gui.b_frame, -1, 5);
    gtk_widget_set_size_request(gui.l_frame, 20, -1);
    gtk_widget_set_size_request(gui.r_frame, 20, -1);

    ///NEU_END
    h_scale=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);                         //NEU
    gui.ring1_l=gtk_label_new("");
    ring1_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_range_set_value(GTK_RANGE(ring1_s), 1);
    //gtk_scale_set_value_pos(GTK_SCALE(ring1_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring1_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring1_s), 0);    
    gtk_widget_set_name(ring1_s, "ring1");
    gui.ring2_l=gtk_label_new("");
    ring2_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    gtk_scale_set_value_pos(GTK_SCALE(ring2_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring2_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring2_s), 0);    
    gtk_widget_set_name(ring2_s, "ring2");
    gui.ring3_l=gtk_label_new("");
    ring3_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    //gtk_scale_set_value_pos(GTK_SCALE(ring3_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring3_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring3_s), 0);    
    gtk_widget_set_name(ring3_s, "ring3");
    gui.ring4_l=gtk_label_new("");
    ring4_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    //gtk_scale_set_value_pos(GTK_SCALE(ring4_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring4_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring4_s), 0);    
    gtk_range_set_value(GTK_RANGE(ring4_s), 12);
    gtk_widget_set_name(ring4_s, "ring4");
    gui.ring5_l=gtk_label_new("");
    ring5_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    //gtk_scale_set_value_pos(GTK_SCALE(ring5_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring5_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring5_s), 0);    
    gtk_range_set_value(GTK_RANGE(ring5_s), 10);
    gtk_widget_set_name(ring5_s, "ring5");
    gui.ring6_l=gtk_label_new("");
    ring6_s=gtk_scale_new_with_range(GTK_ORIENTATION_VERTICAL,0,12,1);
    //gtk_scale_set_value_pos(GTK_SCALE(ring6_s),GTK_POS_BOTTOM);                 //Zahl nach unten?
    gtk_scale_set_draw_value(GTK_SCALE(ring6_s), FALSE);                        //Zahl weg
    gtk_range_set_round_digits(GTK_RANGE(ring6_s), 0);    
    gtk_range_set_value(GTK_RANGE(ring6_s), 12);
    gtk_widget_set_name(ring6_s, "ring6");

    gui.scales[0] = ring1_s;
    gui.scales[1] = ring2_s;
    gui.scales[2] = ring3_s;
    gui.scales[3] = ring4_s;
    gui.scales[4] = ring5_s;
    gui.scales[5] = ring6_s;                //NEU

    
    gui.output = gtk_label_new("Ausgabe:");

    entry=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(entry), 30);                             //reichen 30 zeichen?
    gtk_entry_set_text(GTK_ENTRY(entry), "Terminal");
    gui.terminal = entry;

    h_box2=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    b_help=gtk_button_new_with_label("Hilfe");

    gtk_window_set_default_size(GTK_WINDOW(fenster), 600, 300);                 //Defaultgröße des Fensters: Breite, Höhe
    gtk_window_set_title(GTK_WINDOW(fenster), "Widerstandsrechner");

    gtk_container_add(GTK_CONTAINER(fenster), v_box);
    gtk_box_pack_start(GTK_BOX(v_box), heading, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(v_box), h_box, TRUE, TRUE, 2);

    gtk_box_pack_start(GTK_BOX(h_box), v_leg1, FALSE, FALSE, 0);            //NEU angepasst
    gtk_box_pack_start(GTK_BOX(v_leg1), empty1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(v_leg1), leg1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(v_leg1), empty2, TRUE, TRUE, 0);

    //NEU

    gtk_box_pack_start(GTK_BOX(h_box), v_frame,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(v_frame), gui.t_frame,FALSE, FALSE, 0);
    
    gtk_box_pack_start(GTK_BOX(v_frame), h_scale,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.l_frame,FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring1_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring1_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring2_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring2_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring3_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring3_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring4_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring4_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring5_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring5_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.ring6_l,TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), ring6_s, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(h_scale), gui.r_frame,FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(v_frame), gui.b_frame,FALSE, FALSE, 0);
    //NEU END

    gtk_box_pack_start(GTK_BOX(h_box), v_leg2, FALSE, FALSE, 0);           //NEU angepasst
    gtk_box_pack_start(GTK_BOX(v_leg2), empty3, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(v_leg2), leg2, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(v_leg2), empty4, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(v_box), gui.output, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(v_box), h_box2, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(h_box2), entry, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(h_box2), b_help, FALSE, FALSE, 2);

    g_signal_connect(G_OBJECT(ring1_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring2_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring3_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring4_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring5_s), "value_changed", G_CALLBACK(slider), &gui);
    g_signal_connect(G_OBJECT(ring6_s), "value_changed", G_CALLBACK(slider), &gui);     //NEU
    g_signal_connect(G_OBJECT(entry), "activate", G_CALLBACK(terminal), &gui);          //ENTER-Taste zum "aktivieren"
    g_signal_connect(G_OBJECT(b_help), "clicked", G_CALLBACK(help), NULL);
    g_signal_connect(G_OBJECT(fenster), "delete-event", gtk_main_quit, NULL);
    
    
    gtk_widget_show_all(fenster);

    for (i = 0; i < 6; i++)                 //NEU angepasst
    {
        slider(gui.scales[i], &gui);
    }


    gtk_main();
}







void berechnen (gui_t *pgui)
{
    char inStr[MAXINPUT + MAXOUT];
    int pruef;
	char worte[6][WORTLEN];
    int ringe[6];
    if (gtk_entry_get_text_length (GTK_ENTRY(pgui->terminal))<= MAXINPUT + MAXOUT)
    {
        strcpy (inStr, gtk_entry_get_text(GTK_ENTRY(pgui->terminal)));
        pruef = inputPruefen(inStr);
		if (pruef >= 0)
		{
			aufteilen(inStr, worte, pruef);
		}
		//ausgabe(worte, pruef);
        ausgabeInStr(worte, pruef, inStr, pgui->ringWerte);
        gtk_label_set_text(GTK_LABEL(pgui->output), inStr);

        setzeRFarbe(pgui, pruef);
    }
}

void initColors (gui_t *pgui)
{
    int i;
    //Farbzuweisung
    GdkColor black, brown, red, orange, yellow, green, blue, violet, grey, white, gold, silver, none, temp, beige, lBlue;
    GdkColor *local_colors[] = {&black, &brown, &red, &orange, &yellow, &green, &blue, &violet, &grey, &white, &gold, &silver, &none, &black, &beige, &lBlue};
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
    gdk_color_parse("#D4AF37", &gold);
    gdk_color_parse("#C0C0C0", &silver);
    gdk_color_parse("#F0F0F0", &none);              //so etwa normal?
    
    gdk_color_parse("#E1C699", &beige);             //NEU
    gdk_color_parse("#00BFFF", &lBlue);            //NEU

    for (i = 0; i < 13; i++)
    {
        pgui->colors[i] = *local_colors[i];
    }
    for (i = 0; i < 3; i++)
    {
        pgui->bg_colors[i] = *local_colors[i + 13];
    }

   
}


void setzeRFarbe (gui_t *pgui, int ringzahl)
{
    GdkColor *tmpColor;
    if (ringzahl > 4)           //if "Metallschicht"
    {
        tmpColor = &pgui->bg_colors[2];    //hellblau
        gtk_widget_modify_bg(GTK_WIDGET(pgui->t_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->b_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->l_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->r_frame), GTK_STATE_NORMAL, tmpColor);
    }
    else
    {
        tmpColor = &pgui->bg_colors[1];    //beige
        gtk_widget_modify_bg(GTK_WIDGET(pgui->t_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->b_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->l_frame), GTK_STATE_NORMAL, tmpColor);
        gtk_widget_modify_bg(GTK_WIDGET(pgui->r_frame), GTK_STATE_NORMAL, tmpColor);
    }
}
/*
author: Raupe

Hauptprogramm des Widerstandsrechners mit GUI
Bedienkozepte:
- Kommandozeile der Gui funktioniert wie das Konsolenprogramm
- Hilfetext auch für die Konsole
- Ohne Parameter oder bei allen anderen: Start des Programms mit GUI

*/
#include <string.h>
//#include "Main.h"
#include "gui.h"

#define MAIN_FUNK

//Proto

void printHelp();
//end_proto

int main(int argc, char *argv[])
{
    gui_t gui;
	
    if (argc > 1)
    {
        if (!strcmp(argv[1], "-cmd"))
        {
            main_Konsole();
            return 42;
        }
        if (!strcmp(argv[1], "-?") || !strcmp(argv[1], "-help"))
        {
            printHelp();
            return 42;
        }
    }
    main_gui(argc, argv);


    return 0;
}


void printHelp ()
{
    char hilfeText[800] = {"---Widerstandsrechner---\nEin Programm, dass die Farbringe eines Widerstandes \n"};
    strcat(hilfeText, "decodiert und den Wert angibt.\nNormal wird das Programm mit einer grafischen Anzeige");
    strcat(hilfeText, "\naufgerufen.\n\nKommandozeilenargumente :\n - ? oder - help\n Anzeigen der Hilfe");
    strcat(hilfeText, "(aber das ist anscheinend bekannt)\n - cmd\n Aufruf als Konsolenprogramm\n");
    strcat(hilfeText, "(Bekannt aus der Vollversion des C7.3 Rechners der\n Autoren dieses Programms)\n ");
    printf("%s", hilfeText);
    }
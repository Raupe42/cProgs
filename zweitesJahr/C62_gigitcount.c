/*
author: Raupe

task:
C62 1
1 Ziffernzeichen in einer Datei z¨ahlen
Schreiben Sie ein Programm digitcount.c, welches die Anzahl der Ziffernzeichen in einer Datei
z¨ahlt! Folgendes soll in diesem Programm passieren:
• Eingabe des Pfadnamens einer Datei von der Tastatur
• Lesen des Dateiinhaltes
• bei gleichzeitigem Z¨ahlen der Ziffernzeichen in dieser Datei.
• Ausgabe des Ergebnisses
*/

//defines
//END_defines

//includes
#include <stdio.h>
//END_includes

//structs
//END_structs

//prototypes
//END_prototypes

/*no global variables*/

int main (void)
{
    char input [256];
    FILE * dm;
    
    scanf ("%s", &input);
    //printf ("%s", input);
    dm = fopen (input, "r");
    if (!dm)
    {
        perror (input);
        return 1;
    }
    int count = 0, data;
    data = fgetc (dm);
    while (data != EOF)
    {
        count++;
        data = fgetc (dm);
    }
    printf ("Zeichen: %i", count);
    return 0;
}
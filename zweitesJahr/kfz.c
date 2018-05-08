/*
author: Raupe

task:
Das Program kfz.c soll nach Eingabe eines Kfz-Kennzeichens den Landkreis (bzw. die kreisfreie
Stadt) ermitteln und ausgeben:
Kennzeichen eingeben...........: PB-XY 1234
Landkreis oder kreisfreie Stadt: Paderborn

*/

#include <stdio.h>
#include <string.h>

//proto
char * auswahl (char * input);

//protoEnd

int main (void)
{
    char str [10];
    char * tok;
    printf ("Bitte Kennzeichen eingeben");
    scanf ("%9[^\n]", str);
    tok = strtok (str, "- ");
    printf ("%s\n", auswahl (tok));
}

char * auswahl (char * input)
{
    static char auswahlRet [100] = "";
    if (strcmp ("PB", input) == 0)
        strcat (auswahlRet, "Paderborn");
    else if (strcmp ("GT", input) == 0)
        strcat (auswahlRet, "Guetersloh");
    else if (strcmp ("BI", input) == 0)
        strcat (auswahlRet, "Bielefeld");
    else 
        strcat (auswahlRet, "Nirgendwo");     
}

//Nur aus Spaß
char * auswahl2 (char * input)
{
    static char auswahl2 [100] = "";

    char orte [10] [2] [100];  //Index | kurz/ lang | Text
    orte [0] [0] [0] = '\0';
    strcat (orte [0] [0], "PB");
    strcat (orte [0] [1], "Paderborn");
    
}
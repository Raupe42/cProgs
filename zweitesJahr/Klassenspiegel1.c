/* 
author: Raupe

Task: 
C43A Nr. 2a
*/

//includes
#include <stdio.h>

//prog
int main (void)
{
    //lokale Variablen
    int i, gesZahl;
    int Noten [6];
    double schnitt, notenSumme;
    //einlesen der Eingabe
    printf("Bitte den fertigen Notenspiegel eingeben\n");
    for (i = 0; i < 6; i++)
    {
        printf ("Wie oft kam die Note %i vor: ", i+1);
        scanf ("%i", &Noten[i]);
    }

    //ggf. verarbeiten
    gesZahl = 0;
    for (i= 0; i < 6; i++)
    {
        gesZahl = gesZahl + Noten[i];
    }

    notenSumme = 0;
    for (i = 0; i < 6; i++)
    {
        notenSumme = notenSumme + Noten[i] * (i + 1);
                                 //Anzahl  * Wertigkeit
    }
    schnitt = notenSumme / gesZahl;
    //in dieser Rechnung muss eine (Gleit-) Kommezahl enthlten sein!
    //double = int / int Ergebnis: int
    //double = double / int Ergebnis: double

    //ausgeben 

    printf ("Durchschnitt: %.2lf bei einer Anzahl von %i Klausuren", schnitt, gesZahl);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//argc : Anzahl der Wörter (Trennung durch Leerzeichen) INKLUSIVE des programmnamens
//argv : Array der Wörter des Aufrufes
int main (int argc, char *argv[])
{
    int i;
    char vergleich;
    double ergebnis = 0.0;
    double zahl;

    ergebnis = atof (argv[1]);  //Erste Zahl einlesen und fuer weitere Rechnungen sichern
    for (i = 2; i < argc; i ++)
    {
        if (isdigit (argv[i][0]))   //hier wird davon ausgegangen, dass in einem Array-Feld nur Zahlen oder nur Zeichen stehen
       {
           //is mir doch egal 
       }
       else     //eine Anweisung ist gefunden
        {
            zahl = atof (argv[i+1]);    //dann steht die Zahl ein Feld weiter hinten
            if (strcasecmp (argv[i], "plus") == 0)  //jetzt kann man rechnen
                ergebnis = ergebnis + zahl;
            else if (strcasecmp (argv [i], "minus")== 0)
                ergebnis = ergebnis - zahl;
            else if (strcasecmp (argv [i], "mal")== 0)
                 ergebnis = ergebnis * zahl;
            else if (strcasecmp (argv [i], "geteilt")== 0)
                 ergebnis = ergebnis / zahl;
        }
        
    }

    printf ("\n%g\n", ergebnis);

}

/*
a.exe
3
minus
8
plus
4
...
*/
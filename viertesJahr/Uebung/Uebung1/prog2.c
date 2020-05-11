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
    double zahl [200];
    char zeichen [200] [200];

    ergebnis = atof (argv[1]); //Erste Zahl einlesen und fuer weitere Rechnungen sichern
    for (i = 2; i+1 < argc; i = i + 2)
    {

            zahl [0] = atof (argv[i+1]);
            
            if (strcasecmp (argv[i], "plus") == 0)
                ergebnis = ergebnis + zahl [0];
            else if (strcasecmp (argv [i], "minus")== 0)
                ergebnis = ergebnis - zahl [0];
            else if (strcasecmp (argv [i], "mal")== 0)
                 ergebnis = ergebnis * zahl [0];
            else if (strcasecmp (argv [i], "geteilt")== 0)
                 ergebnis = ergebnis / zahl [0];
        
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
/*
author: Tim, Jens 

Task: Erfüllung des Pflichtenhefts gemäß der Dokumentation.
Dieses Programm stellt das Prdukt als vereinbarte Grundversion dar.

*/

// Defines
#define MaxInput 99
#define WortLen 30
#define Varianten 8

#define xstr(x) #x
#define str(x) xstr(x)
//End Defines

//Includes 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//End Includes

//Proto
int aufteilen (char *zk, char *w1, char *w2 char *w3, char *w4);
int farbringe2Ziffer (char *farbwort);
double farbring2Multi (char *farbwort);
double farbring2Tolleranz (char *farbwort);

char * defineVglArr ();
void cpyArrOfStr (char dest [] [], char source [] []);
//End Proto

int main (void)
{
    //lokale Datenfelder
    char inputStr [MaxInput+1];
   /* char w1 [WortLen];
    char w2 [WortLen];
    char w3 [WortLen];
    char w4 [WortLen];
    */
    char worte [4] [WortLen];
    //End lokale Datenfelder

    //Begruessung und Arbeitsauftrag fuer den Benutzer
    printf ("Gib die bloeden Ringe ein!!!");

    scanf ("%" xstr(MaxInput) "[^\n]", inputStr);
    //Aufruf der Subroutinen
    aufteilen (inputStr, worte [0], worte [1], worte [2], worte [3]);

    printf ("%i", farbringe2Ziffer (worte [0]));
    //Ausgabe an den Benutzer
    
}

int aufteilen (char *zk, char *w1, char *w2 char *w3, char *w4)
{
    w1 = strtok (zk, "-");   //nicht - ist Fehler
    w2 = strtok (NULL, "-");
    w3 = strtok (NULL, "-");
    w4 = strtok (NULL, "-");
    // reste verwerten
    return 0;
}
int farbringe2Ziffer (char *farbwort);
{
    char * vgl = defineVglArr ();
    int farbe, var, retValInt;
    char retValStr [20];

    for (farbe = 0; farbe < 12; farbe ++)
    {
        for (var = 1; var < Varianten; var ++)
        {
            //suchen durch vergleichen
            if (strcmp (vgl [farbe] [var], farbwort) == 0)
            {
                retValStr = vgl [farbe] [0];
                char c = retValStr [0];
                retValInt = (c - '0');
                return retValInt;
            }
            //wenn etwas gefunden wurde
            // aktuelle zeile feld 0 -> ergebenis
        }
    }
    return -1;
}
double farbring2Multi (char *farbwort)
{

}
double farbring2Tolleranz (char *farbwort)
{

}

char * defineVglArr ()
{
    static char vglArr [12] [Varianten] [20];

    char sw [Varianten] [20] = {"0", "schwarz", "sw", "black", "bk"};
    char br [Varianten] [20] = {"1", "braun", "br", "brown", "bn"};
    char rt [Varianten] [20] = {"2", "rot", "rt", "red", "rd"};
    char or [Varianten] [20] = {"3", "orange", "or", "og"};
    char ge [Varianten] [20] = {"4", "gelb", "ge", "yellow", "ye"};
    char gn [Varianten] [20] = {"5", "grue", "gn", "green"};
    char bl [Varianten] [20] = {"6", "blau", "bl", "blue", "bu"};
    char vi [Varianten] [20] = {"7", "violett", "vi", "voilet", "vt", "lila", "vio"};
    char gr [Varianten] [20] = {"8", "grau", "gr", "grey", "gy"};
    char ws [Varianten] [20] = {"9", "weiss", "ws", "white", "wh", "weis"};
    char au [Varianten] [20] = {"A", "gold", "au", "go", "gd"};
    char ag [Varianten] [20] = {"B", "silber", "si", "silver", "sr", "ag"};
    cpyArrOfStr (vglArr [0], sw);
    cpyArrOfStr (vglArr [1], br);
    cpyArrOfStr (vglArr [2], rt);
    cpyArrOfStr (vglArr [3], or);
    cpyArrOfStr (vglArr [4], ge);
    cpyArrOfStr (vglArr [5], gn);
    cpyArrOfStr (vglArr [6], bl);
    cpyArrOfStr (vglArr [7], vi);
    cpyArrOfStr (vglArr [8], gr);
    cpyArrOfStr (vglArr [9], ws);
    cpyArrOfStr (vglArr [10], au);
    cpyArrOfStr (vglArr [11], ag);



    return vglArr;
}

void cpyArrOfStr (char * dest [], char * source [])
{
    int i;
    for (i = 0; i < 12; i ++)
    {
        strcpy (dest [i], source [i]);
    }
}
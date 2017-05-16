/* 
author: Raupe
Aufgabe: C19A

a) 
Verwendete Schleifen:
- Fallunterscheidung
- Abweisende Schleife
- Mehrfachauswahl

b)
Programm

*/

#include <stdio.h>

int main (void)
{
    //VarDec
    int vw;
    //VarInit
    vw = 0;

    //Intro + Input
    do {
        printf ("\nOrtsvorwahl eigeben: ");
        scanf ("%i", &vw);
       // printf ("\n");

        switch (vw)
        {
            case 521:
            printf ("Bielefeld");
            break;

            case 571:
            printf("Minden");
            break;

            case 5221:
            printf ("Herford");
            break;

            case 0:
            break;

            default:
            printf("Fehler");
        }
    } while (vw != 0);
}
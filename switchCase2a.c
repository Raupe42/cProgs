/* 
autor: Raupe

Aufgabe: C19A 2

a)
 Schreiben Sie ein Programm, das zwei Zahlen einliest und anschließend - je nach Wunsch
- diese Zahlen addiert, subtrahiert, dividiert oder multipliziert. Was zu tun ist, soll per
Zahlencode eingegeben werden (1: addieren, 2: subtrahieren, 3: multiplizieren, 4: dividieren).

b) Erweitern Sie dieses Programm so, dass es diese Operationen immer wieder ausfuhrt, bis der ¨
Benutzer den Zahlencode 0 eingibt.

*/

//includes
#include <stdio.h>

int main (void)
{
    //VarDef
    int zahl1, zahl2, mode;
    double ergebnis;

    //VarInit
    zahl1 = zahl2 = mode = 0;
    ergebnis = 0.;

    //Intro + Input
    printf("Bitte zwei Zaholen eingeben: ");
    scanf ("%i", &zahl1);
    scanf ("%i", &zahl2);
    
    printf("Wie sollen diese Zahln verrechnet werden\?\n");
    printf("1 addieren\n2 subtrahieren\n3 multiplizieren\n4 dividieren\n");
    scanf ("%i", &mode);

    //Calc + Out

    switch (mode)
    {
        case 1: 
            ergebnis = zahl1 + zahl2;
            break;
        case 2: 
            ergebnis = zahl1 - zahl2;
            break;
        case 3:
            ergebnis = zahl1 * zahl2;
            break;
        case 4:
            if (zahl2 != 0)
            ergebnis = zahl1 / zahl2;
            break;
        default:
            printf ("falsche Eingabe\n");
            return 1;
    }

    printf ("Ergebnis: %g", ergebnis);
}
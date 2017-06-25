/*
author: Raupe

Aufgabe: C25A 2
a) Erstellen Sie eine Funktion void hbalken(unsigned int x)! Beim Aufruf hbalken(3)
soll ein horizontaler Balken aus 3 Sternen ausgegeben werden, anschlieÿend ein Zeilenende.
Testen Sie diese Funktion mit einem kleinen Programm (hbalken.c)!

b) Erstellen Sie eine erweiterte Funktion void hbalkenpm(int x); falls der Parameter positiv
ist, soll ein Balken aus Sternchen ausgegeben werden; falls er negativ ist, soll ein Balken
aus Rauten ("#") ausgegeben werden. Ist der Parameter null, soll eine Null ausgegeben
werden. Testen Sie auch diese Funktion mit einem kleinen Programm (hbalkenpm.c)

*/

//includes
#include <stdio.h>

//proto

void hbalken (unsigned int x);
void hbalkenpm (int x);

int main (void)
{
    hbalken (3);

    hbalkenpm (3);
    hbalkenpm (-3);
    hbalkenpm (0);
}

/* a) */
void hbalken (unsigned int x)
{
    //laufvar
    int i;
    //operation
    for (i = 0; i < x; i++)
    {
        printf ("*");
    }
    printf ("\n");
}

/* b) */

void hbalkenpm (int x)
{
    //local var 
    int i,n;        //n = Anzahl d. Zeichen
    char c;

    if (x > 0)
    {
        c = '*';
        n = x;
    }
    else if (x < 0)
    {
        c = '#';
        n = x * (-1);
    }
    else 
    {
        c = '0';
        n = 1;
    }

    for (i = 0; i < n; i++)
    {
        printf ("%c", c);
    }
    printf ("\n");
}
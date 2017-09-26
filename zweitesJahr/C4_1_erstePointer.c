/*
author: Raupe

Aufgabe:
Umgang mit Adressvariablen
• int x=1;
• int *px=NULL;
• px soll die Adresse von x erhalten.
• *px soll auf -3 gesetzt werden.
Nun sollen mit printf() ausgedruckt werden:
• x
• &x
• px
• &px
• *px

Ergebnis:
Variable    int x        int *px
Adresse     0061FF2C     0061FF28
Inhalt      -3           0061FF2C

out raw:
x= -3
&x= 0061FF2C
px= 0061FF2C
&px= 0061FF28
*px= -3

*/

//includes

#include <stdio.h>

//prog

int main (void)
{
    int x = 1;
    int *px = NULL;

    px = &x;

    *px = -3;

    printf ("x= %i \n&x= %p \npx= %p \n&px= %p\n *px= %i", x, &x, px, &px, *px);
}
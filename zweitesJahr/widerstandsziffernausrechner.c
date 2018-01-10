/* 
author: Raupe

Aufgabe: Eingsbe einer Ziffer - Ausgabe der Widerstandsfarbe
*/

#include <stdio.h>

int main (void)
{
    char farbArr [11][10]={
    "SW",
    "BR",
    "RT",
    "OR",
    "GE",
    "GN",
    "BL",
    "VIO",
    "GR",
    "WS",
    "unbekannt"};

    char str [2];
    int in;
    printf ("Ziffer: ?\n");
    scanf ("%i", &in);
    printf("%s\n", farbArr[in]);
}
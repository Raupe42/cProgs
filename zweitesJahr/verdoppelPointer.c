/*
author: Raupe

Aufgabe:

x verdoppel über Point in Funktion
*/
#include <stdio.h>

void verdoppel (int * x)
{
    *x = (*x + *x);
}

int main (void)
{
   int x = 5;
    verdoppel(&x);
    printf ("%i", x);
}
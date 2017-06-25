/*
author: Raupe

Aufgabe:
Rechteck aus * zeichnen

*/

//includes
#include <stdio.h>

// Proto
void rechteck (int h, int l);
void dreieck (int h);

int main (void)
{
    //rechteck (2,5);
    dreieck (5);
   // printf ("blaa");
    return 0;
}

void rechteck (int h, int l)
{
    for (int i = 0; i < h; i++)
    {
        for (int ii = 0; ii < l; ii++)
        {
            printf ("*");
        }
        printf ("\n");
    }
    return; 
}

void dreieck (int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int ii = 0; ii < i; ii++)
        {
            printf ("*");
        }
        printf ("\n");
    }
    return; 
}
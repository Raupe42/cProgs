/*
author: Raupe

task: C48A 2

a)
int get_maximum (int feld [], int anzahl)
b)
um zu wissen, wie viele Felder int feld [] enthält, damit keine Speicherzugriffsverletzung statt findet


*/

#include <stdio.h>


int get_maximum_fuer_c (int feld [], int anzahl)
{
    return 0;
}

int get_maximum (int feld [], int anzahl)
{
    int max = feld[0], i;
    for (i = 0; i < anzahl; i++)
        if (feld[i] > max)
            max = feld [i];
    return max;
}

int get_maximum_alt (int * feld, int anzahl)
{
    int i, max = *feld;
    for (i = 0; i < anzahl; i++)
        if (*(feld+i) > max)
            max = *(feld+i);
    return max;
}

int main (void)
{
    int x [7] = {20, 50, 30, 10, 90, 110, 60};
    printf ("%i\n", get_maximum_fuer_c(x, 7));
    printf ("%i\n", get_maximum_alt(x,7));
}
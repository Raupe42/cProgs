#include <stdio.h>

int main (void)
{
    double d;
    double werte [32];
    int i;

    for (d = 0.; d < 3.14; d = d + 0.1)
    {
        printf ("%.2lf\n", d);
    }
d = 0.;
i = 0;
    while (d < 3.14)
    {
        printf ("%.2lf\n", d);
        werte [i] = d;
        d = d + .1;
        i++;
    }
}

void WerteAuswserten ()
{
    //Array lesen und mit Werten arbeiten
}
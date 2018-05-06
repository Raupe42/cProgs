#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main (void)
{
    double d;
    double werte [32];
    int i;
    printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN);
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG);
    printf("%scyan\n", KCYN);
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KNRM);
    getchar();
    /*
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
    int x = 4;
    {       
        x = 5;
    }

    printf ("%i", x);
    */
}

void WerteAuswserten ()
{
    //Array lesen und mit Werten arbeiten
}
#include <stdio.h>
#include <stdlib.h>

void sortiere(double *px, double *py, double *pz)
{
    double buff;
    if (*pz < *py || *pz < *px)
    {
        if (*py < *px)
        {
            buff = *pz;
            *pz = *px;
            *px = buff;
        }
        else
        {
            buff = *pz;
            *pz = *py;
            *py = buff;
        }
    }
}

int ist_dreieck(double a, double b, double c)
{
    if (a < 0. || b < 0. || c < 0)
        return 0;
    if (a + b <= c)
        return 1;
    else
        return 0;
}

int ist_rwdreieck(double a, double b, double c)
{
    if (((a * a) + (b * b)) == (c * c))
        return 1;
    else
        return 0;
}

int main(void)
{
    double a = 0., b = 0., c = 0;
    printf("Eingabe a, dann b, dann c\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    sortiere(&a, &b, &c);
    if (ist_dreieck(a, b, c))
        printf("Die Punlkte bilden ein Dreieck\n");
    if (ist_rwdreieck(a, b, c))
        printf("Die Punkte bilden sogar ein rechtwinkliges Dreick\n");
    return 0;
}
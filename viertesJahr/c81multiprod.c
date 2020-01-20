#include "stdio.h"
#include "stdarg.h"

double multiprod (int, ...);

int main (void) 
{
    double x;
    x = multiprod (3, 5., 2., 3.);
    printf ("%g\n", x);
    return 0;
}

double multiprod (int anzahl, ...)
{
    double retVal = 0;
    int i;
    va_list liste;
    

    va_start (liste, anzahl);
    retVal = 1;// va_arg (liste, double);
    for (i = 0; i < anzahl; i++)
    {
        retVal *= va_arg (liste, double);
    }
    va_end (liste);
    return retVal;
}
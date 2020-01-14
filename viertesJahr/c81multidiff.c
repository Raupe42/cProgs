#include "stdio.h"
#include "stdarg.h"

double multidiff (int, ...);

int main (void) 
{
    double x;
    x = multidiff (4, 3.5, 0.2, 0.1, 0.3, 0.4);
    printf ("%g\n", x);
    return 0;
}

double multidiff (int anzahl, ...)
{
    double retVal = 0;
    int i;
    va_list liste;
    

    va_start (liste, anzahl);
    retVal = va_arg (liste, double);
    for (i = 0; i < anzahl; i++)
    {
        retVal -= va_arg (liste, double);
    }
    va_end (liste);
    return retVal;
}
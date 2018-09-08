/*
math.h:
double sin(double x) : Sinus
double cos(double x) : Cosinus
double sqrt (double x): Wurzel
double fabs(double x): Betrag

---

double ewg (double x)
{
    if (x < 0.0)
        return 0.0;
    return x;
}
*/

#include <stdio.h>
#include <math.h>

void printTab (double (*pf) (double));

int main (void)
{
    double x;


    double (*pf) (double);
    //Funktionszeiger auf eine Funktion mit Parameterliste (double) und RetVal double
    pf = sqrt;

    x = pf (4.0);
    printTab (sin);
    printf ("%g", x);
}

void printTab (double (*pf) (double))
{
    double x, y;
    for (x = 0.0; x <= 3.14; x = x + 0.01)
    {
        y = pf (x);
        printf ("%.4f, %.4f \n", x, y);
    }
}
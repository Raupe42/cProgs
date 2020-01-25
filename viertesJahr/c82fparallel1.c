#include <stdio.h>

double f (double a, double b)
{
    return ((a*b)/(a+b));
}

int main (void)
{
    double a, b, c;
    printf ("PS\n");
    scanf ("%lf", &a);
    scanf ("%lf", &b);

    c= f (a, b);

    printf ("Ausgabe: %g", c);

    return 0;
}
#include <stdio.h>
#include <setjmp.h>
jmp_buf jmpBuffer;

double f (double a, double b)
{
       if (a+b == 0)
        longjmp (jmpBuffer, 1);
    return (a*b)/(a+b);
}

int main (void)
{
    double a, b, c;
    int rc;
    printf ("RS\n");
    rc = setjmp (jmpBuffer);
    if (rc)
        printf ("ERR");
    scanf ("%lf", &a);
    scanf ("%lf", &b);
    c= f (a, b);
    printf ("Ausgabe: %g", c);

    return 0;
}
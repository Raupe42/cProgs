// author: Raupe
#include <stdio.h>
int main (void)
{
    // VarDef
    int x, i;
    // VarInit
    x = 0;

    // Calc + Out

    for (i = -5; i <= 5; i++)
    {
        x = i;

        printf ("%i          %i\n",i, (x*x - (6*x) + 4));

    }
}
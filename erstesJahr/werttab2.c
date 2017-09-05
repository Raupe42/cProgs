// author: Raupe
#include <stdio.h>
#include <math.h>
int main (void)
{
    // VarDef
    int i;
    double cosErg,x;
    // VarInit
    x = 0;

    // Calc + Out

    for (i = 0; i <= 90; i += 3)
    {   
        x = i;
        x = x/180 * M_PI;
        cosErg = cos (x);
        
        printf ("%i          %lf\n",i, cosErg);

    }
}
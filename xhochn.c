// author: Raupe

#include <stdio.h>

int main (int x, int n)
{
    //VarDef + VarInit
    long int ret = x;
    int i = 0;

    for (i = 0; i < n; i ++)
    {
        ret = ret * x;
    }
    printf ("%li", ret);
}
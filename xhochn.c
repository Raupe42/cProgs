// author: Raupe

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv []) //c count; v vlaues
{
    if (argc < 3)
    {
        printf ("Aufrufparam: x hoch n mit positievem x n");
     return 1;
    }
   
    //VarDef + VarInit
    long int ret;
    int i, x ,n;
    i = 0;
    x = atoi (argv [1]);
    n = atoi (argv [2]);
    ret = x;
    if (n >= 1)
    {
        for (i = 1; i < n; i ++)
            {
                ret = ret * x;
            }
        printf ("%li", ret);
    }
    else
    {
        if (n == 0 && x != 0)
        {
            ret = 1;
            printf ("x hoch 0 ist IMMER 1");
        }
        else
        {
            if (x == 0)
                printf ("0 hoch 0 ist nicht definiert");
            else
                printf ("flasche Eingabe");
        }
    }
    return 0;
}
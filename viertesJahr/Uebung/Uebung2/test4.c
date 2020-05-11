#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void rToL (char pStr [])
{
    int i = 0;

    for (i = 0; i < strlen(pStr); i ++)
    {
        if (pStr [i] == 'r')
            pStr [i] = 'l';
    }
}

int *dings (int a, int b)       
{
    static int arr [50] = {0};  //MUSS static sein
    arr [0] = a;
    arr [1] = b;
    return arr;
}

int main (void)
{
    int lArr [5] = {0};
    int *pArr;
    char str [] = "Dies ist ein Text der fuer manche nicht aussprechbar ist.";
    printf ("%s\n", str);
    rToL (str);
    printf ("%s\n", str);

    printf ("%i %i\n", lArr [0], lArr [1]);
    pArr = dings (5,6);
    printf ("%i %i\n", pArr [0], pArr [1]);
}
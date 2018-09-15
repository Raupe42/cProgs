/*
author: Raupe

Task: C65A1d
*/

#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 5
#define SLEN 20

int verglStr (const char*, const char*);

int main (void)
{
    char arr [ANZAHL] [SLEN] = {"apfel", "zitrone", "kirsche", "mirabelle", "zander"};
    int i;

    qsort (arr, ANZAHL, SLEN, verglStr);

    for (i = 0; i < ANZAHL; i++)
    {
        printf("%s<", arr[i]);
    }    
}

int verglStr (const char * pa, const char * pb)
{
   // printf ("%i    %i\n", *pa, *pb);
   while (*pa == *pb && *pa != 0 && *pb != 0)
   {
       pa += sizeof (char);
       pb += sizeof (char);
   }
    return (*pa-*pb);
}
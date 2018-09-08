/*
author: Raupe

Task C65A1c
*/

#include <stdio.h>
#include <stdlib.h>

int verglChar (const char*, const char*);

int main (void)
{
    char arr [] = "zitrone";
    int i;

    qsort (arr, strlen (arr), sizeof (char), verglChar);

    for (i = 0; i < 10; i++)
    {
        printf("%c", arr[i]);
    }    
}

int verglChar (const char * pa, const char * pb)
{
   // printf ("%i    %i\n", *pa, *pb);

    return (*pa-*pb);
}
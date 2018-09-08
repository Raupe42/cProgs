/*
*/

#include <stdio.h>
#include <stdlib.h>

int verglint (const int*, const int*);

int main (void)
{
    int arr [10] = {7, 3, 5, 2, 4, 1, 9, 8, 1, -2};
    int i;

    qsort (arr, 10, sizeof (int), verglint);

    for (i = 0; i < 10; i++)
    {
        printf("%i", arr[i]);
    }    
}

int verglint (const int * pa, const int * pb)
{
    return (*pa-*pb);
}
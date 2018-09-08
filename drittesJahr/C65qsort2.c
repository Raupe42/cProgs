/*
author: Raupe

Task: C65A1b

*/

#include <stdio.h>
#include <stdlib.h>

int verglintNeg (const int*, const int*);

int main (void)
{
    int arr [10] = {7, 3, 5, 2, 4, 0, 9, 8, 1, -2};
    int i;

    qsort (arr, 10, sizeof (int), verglintNeg);

    for (i = 0; i < 10; i++)
    {
        printf("%i>", arr[i]);
    }    
}

int verglintNeg (const int * pa, const int * pb)
{
   // printf ("%i    %i\n", *pa, *pb);
    return (-*pa+*pb);
}
/*
author: Raupe

Task: C65A1g
*/

#include <stdio.h>
#include <stdlib.h>

#define ANZAHL 3

struct person_t
{
    char vn[20];
    char nn[20];
    int j, m, t;
};
int verglGebT(const struct person_t *, const struct person_t *);

int main(void)
{
    struct person_t arr[ANZAHL] = {{"Emil", "Meier", 1960, 10, 20},
                                   {"Erwin", "Mueller", 1970, 11, 15},
                                   {"Egon", "Moser", 1980, 10, 24}};
    int i;

    qsort(arr, ANZAHL, sizeof(struct person_t), verglGebT);

    for (i = 0; i < ANZAHL; i++)
    {
        printf("%i.%i  %s %s\n", arr[i].m, arr[i].t, arr[i].vn, arr[i].nn);
    }
}

int verglGebT(const struct person_t *pa, const struct person_t *pb)
{
    // printf ("%i    %i\n", *pa, *pb);
    /* while (*pa == *pb)
   {
       pa += sizeof (char);
       pb += sizeof (char);
   }
    return (*pa-*pb);
    */
    /*   if (pa->m == pa->m)
    {
        printf("-%i-  -%i-\n", pa->m, pb->m);
        return (pa->t - (*pb).t);
    }

        return (pa->m - pb->m);

 */

    int a, b;
    a = pa->m * 100 + pa->t;
    b = pb->m * 100 + pb->t;
    return (a - b);
}
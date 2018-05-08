#include <stdio.h>
#include <string.h>

int funk (unsigned long arr [])
{
    printf ("%i", sizeof (arr));
}

int main (void)
{
    unsigned long arr [2000];
    printf ("%i", sizeof (arr));
    funk (arr);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    float f = 3.14;
    char str [20];
    strcpy (str, ftoa (f));
}
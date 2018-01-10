/*
author: Raupe

Task: C46A

*/

#include <stdio.h>

int main (void)
{
    char string [80] = "Hallo";
    char * p;
    p = string;

    printf ("&p %p\n", &p);
    printf (" p %s\n", p);
    printf ("*p %p\n", *p);
    printf ("&string %p\n", &string);
    printf (" string %s\n", string);
    printf ("*string %p\n", *string);
    printf (" string [0] %c\n", string [0]);
    printf (" &string[0] %p\n", &string[0]);

}
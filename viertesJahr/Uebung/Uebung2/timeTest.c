#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main (void)
{
    time_t x;
    x = time(NULL);
    printf ("Laenge von time_t: %i", sizeof(time_t));
    printf ("x ist: %i", x);
    x = time(&x);
    printf ("x ist: %i", x);

}
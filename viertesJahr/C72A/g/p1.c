#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "time.h"
int main (void)
{
    int x, y;
    srand (getpid() + time (NULL));
    x = rand () % 10;
    y = rand () % 10;
    printf ("Wie viel ist %i + %i\n", x, y);
    printf ("%i\n", x+y);
    return 0;   
}
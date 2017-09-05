/* 
author: Raupe

some stuff to test

*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

//local header
void consoleRefresh();
void writeSomething();
void rechnen ();
void stackoverflow (int a);

int main(void)
{
    rechnen ();
    //stackoverflow (0);
}

void consoleRefresh()
{
    for (int i = 0; i < 100; i++) {
     writeSomething();
     system("@cls||clear");
    }
}

void writeSomething()
{
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
       
    }
     sleep (1);
}

void rechnen ()
{
    int a = 2;
    double d = 3.5;
    int b;

    printf ("%g\n", 999.9);
    b = a + d;
    printf ("%i\n", b);
}

void rechnen2 ()
{
    int a = 2;
    double d = 3.5;
    int b;
    printf ("%g\n", 999.9);
    b = a + d;
    printf ("%p\n", &b);
    printf (">%g ## %p - %i ## %p <\n",b, &b, b, &b);

}

void stackoverflow (int a)
{
    printf ("a:%p\n",&a);
    stackoverflow (a);
    printf ("ende");
}
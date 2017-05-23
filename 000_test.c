/* 
author: Raupe

some stuff to test

*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//local header
void consoleRefresh();
void writeSomething();

int main(void)
{
    consoleRefresh();
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
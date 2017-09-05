#include <stdio.h>

int main (void)
{
    //initialisieren
    int i = 0;
    //zuweisen
    i = 32;
    while (i < 128)
    {
        putchar (i);
        i++;
    }
}
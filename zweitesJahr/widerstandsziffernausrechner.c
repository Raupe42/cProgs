/* 
author: Raupe

Aufgabe: Eingsbe einer Ziffer - Ausgabe der Widerstandsfarbe
*/

#include <stdio.h>

int main (void)
{
    int * pi;
    int i;
    char * pc;
    char c;


    pc = &c;
    *pc = '5';
    //printf ("%c", c);
    i = *pc;
    //i = i - '0';
    //oder
    i = i - 48;
    printf ("%i", i);
}
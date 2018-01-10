/* 
autor: Raupe

Aufgabe: C45A1
*/
#include <stdio.h>


int main (void)
{
    int d,m,j;
    char monthArr [12] [20] = {"JAN", "FEB", "MÄR", "APR", "MAI", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

    printf ("Eingabe Tag: ");
    scanf ("%i", &d);
    printf ("Eingabe Monat: ");
    scanf ("%i", &m);
    printf ("Eingabe Jahr: ");
    scanf ("%i", &j);
    while (getchar != '\n');
    printf("\n");
    if (d < 1 || d > 31 || )
    printf ("Es ist der %i. %s %i", d, monthArr [(m-1)], j);
}


























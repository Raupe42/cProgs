/*
author: Raupe

task: alle ASCII Zeichen 32-  127

*/


/*
für Abfragen gibt es 

isalpha
isdigit

aufruf über 
man isalpha

*/

//includes
#include <stdio.h>
#include <stdlib.h>

//local header
void ausgabe ();

int main (void)
{
    ausgabe ();
}
/* Kopiert 
führt cls aus
*/
void clrscr()
{
    system("@cls||clear");
}
/* Ende kopiert */


void ausgabe ()
{
    int i = 0;
    clrscr();
    for (i = 32; i < 128; i++)
    {
        putchar (i);
        fflush (stdout);    //Ausgabepuffer sofort ausgeben
    }
    printf("%i", '\n');
}




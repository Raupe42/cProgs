/* author: Raupe
Aufgabe: C3.1 2

inhalt einer Datei?? mit Zeilennummern ausgeben

*/

//includes
#include <stdio.h>

//prog

int main (void)
{
    int c = 0;
    int num = 0; //Zeilenummer
    c = getchar ();
    while (c!=-1)
    {
        printf ("/* %i */", num);
        num++;
        while (c != '\n')
        {
            putchar (c);
            c = getchar ();
        }
        putchar ('\n');
        c = getchar ();
    }
}
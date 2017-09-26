/*
author: Raupe

Aufgabe:
1. Caesar-Scheibe implementieren

C3.1

*/
//import
#include <stdio.h>
#include <ctype.h>  //isalpha usw.

//proto
void caesar ();

//main
int main (void)
{
    caesar();
    return 0;
}

//func
void caesar ()
{
    //local Var
    int offset;
    char c;
    //input offset
 //   printf ("Bitte Zahl eingeben (0-26)\n");
   // scanf ("%i", &offset);
    offset = 1;
    printf ("\nBitte Text eingeben\n");

    //while (getchar()!='\n'){}   //eingabepuffer leeren

    c = getchar();
    while (c != '\n')
    {
        if (isalpha(c))
        {
            switch (c)
            {
                case 'Z':
                    c = 'A';
                    break;
                case 'z':
                    c = 'a';
                    break;
                default:
                    c = c + offset;
            }
        }
        putchar (c);
        c = getchar ();
    }
    putchar ('\n');

    
}
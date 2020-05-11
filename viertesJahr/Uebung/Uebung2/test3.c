#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//aufgabe: bei eingabe a.exe 10 log.mikail summe berechnen
int main (int argc, char *argv [])
{
    int i= 0, j = 0, k = 0; //braucht man immer 
    FILE *pFile;
    char buff [100], *pStr, *c;
    int erg, zahl;
    if (argc < 2)
        return -1;

    for (i = 1; i < argc; i++)
    {
        if (isdigit (argv [i] [0]))  //dann ist das wohl eine zahl
        {
            zahl = atoi (argv [i]);
            erg += zahl;
        }
        else
        {
            pFile = fopen (argv [i], "r");
            zahl = 0;
             while (fgets (buff, 99, pFile) != NULL)
            {
                //c = fgets (buff, 99, pFile);    //z.B. '1' ' ' '2' '\0'
                zahl = 0;
                pStr = strtok (buff, " ");    //buff: '1' '\0' '2' '\0'
                zahl = atoi(pStr);

                erg += zahl;
                printf ("%i\n", zahl);
                while (pStr != NULL)     
                {
                    zahl = 0;
                    pStr = strtok (NULL, " ");
                    zahl = atoi(pStr);
                    printf ("%i\n", zahl);
                    erg += zahl;
                }
                                
            }
            fclose (pFile);
        }       
    }
printf ("%i", erg);

}
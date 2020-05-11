#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int i;
    double retVal = 0;
    double numA = 0, numB = 0;
    FILE *file;
    char buff [100];
    for ( i = 0; i < argc; i++)
    {
        if (isdigit (argv[i][0]))
        {
            numA = atof (argv[i]);
        }
        else
        {
            if (strcmp (argv[i], "plus"))
                retVal += numA;
            else if (argv [i], "minus")
                retVal -= numA;
            else if (argv [i], "mal")
                retVal *= numA;
            else if (argv [i], "geteilt")
                retVal /= numA;   
        }
    }

    printf ("Ausgabe: %g", retVal);

    file = fopen ("log.txt", "a");
    if (!file)
        return -1;
    sprintf (buff, "Eingabe: ");
    for (i = 0; i < argc; i ++)
    {
        strcat (buff, argv [i]);
    }
    strcat (buff, "\n");
    fputs (buff, file);

    sprintf (buff, "Ausgabe: %g\n", retVal);
    fputs (buff, file);

    fclose (file);
    return 0;
}
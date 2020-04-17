#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int zaehler = 0;
    FILE *file = NULL;
    char dateiname [100];
    char dateiNameAnfang [] = "Test";

    do {
        sprintf (dateiname, "%s%i%s", dateiNameAnfang, zaehler, ".test");  
        file = fopen (dateiname, "w");
        printf ("offen: %i\n", zaehler);
        zaehler ++;
    } while (file); //laeuft bis 65533
    perror ("Error:");
    return 0;
}
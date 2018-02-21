/* 
author: Raupe

task: Strings appenden

*/
//includes
#include <stdio.h>
#include <string.h>


int main (void)
{
    char erg [500]= "";
    char titel [50];
    char vorname [250];
    char nachname [400];
    printf ("Bitte Titel eingeben:\n");
    scanf ("%50s", titel);
    printf ("Bitte Vornamen eingeben:\n");
    scanf ("%250s", vorname);
    printf ("Bitte Nachnamen eingeben:\n");
    scanf ("%400s", nachname);
    //printf ("%i", strlen (titel));
    if ((strlen(titel) + strlen (vorname) + strlen (nachname)) <= 499)
    {
        strcat (erg, titel);
        strcat (erg, " ");
        strcat (erg, vorname);
        strcat (erg, " ");
        strcat (erg, nachname);
        printf ("Gesamte Eingabe: %s\n",erg);

        strcpy (erg, "");

        strcat (erg, nachname);
        strcat (erg, ", ");
        strcat (erg, vorname);
        strcat (erg, ", ");
        strcat (erg, titel);
        printf ("Ablagename: %s\n",erg);

    }
    else{
        printf ("Eingabe zu lang!");
    }

    

}
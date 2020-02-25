#include <stdio.h>

// aus b

#include <string.h>
#define MAX_ANZAHL 200
//char glob_fragefeld [MAX_ANZAHL] [2] [81];

unsigned short int feld_laden (char fragefeld [] [2] [81])
{
    int i = 0;
    strcpy (fragefeld [i] [0], "Welcher Buchstabe kommt nach A?");
    strcpy (fragefeld [i] [1], "B");
    i++;
    strcpy (fragefeld [i] [0], "Welcher Buchstabe kommt nach B?");
    strcpy (fragefeld [i] [1], "C");
    i++;
    strcpy (fragefeld [i] [0], "Welcher Buchstabe kommt nach C?");
    strcpy (fragefeld [i] [1], "D");
    i++;
    strcpy (fragefeld [i] [0], "Welcher Buchstabe kommt nach D?");
    strcpy (fragefeld [i] [1], "E");
    i++;
    return i;
}

//END_aus b
//aus c
typedef char t_fragefeld [] [2] [81];

/*
    Returns: 1 richtig, 0 FALSCH
*/
short int eineFrageStellen (short int eintrNr, t_fragefeld fragefeld )
{
    char antw [81];
    short int falsch = 1;
    //zu einem Eintrag Frage stellen
    printf ("%s\n", fragefeld [eintrNr] [0]);

    //Antwort einlesen
    scanf ("%s", antw);
    //vergleichen
    falsch = strcmp (fragefeld [eintrNr] [1] , antw);
    //Wenn Richtig mitteilen sonst korrekt hinschreiben
    if (!falsch)
        printf ("ok\n");
    else 
        printf ("Nope: %s\n", fragefeld [eintrNr] [1]);
    
    return !falsch;

}

//END_aus c

int main (void)
{
    short int anzahl;
    int i;
    char fragefeld [MAX_ANZAHL] [2] [81];
    anzahl = feld_laden (fragefeld);
    for (i = 0; i < anzahl; i ++)
        eineFrageStellen (i, fragefeld);
    return 0;
}

// S T R U K T O G R A M ist eine separate Datei
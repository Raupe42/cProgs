#include <string.h>
#define MAX_ANZAHL 200
char fragefeld [MAX_ANZAHL] [2] [81];

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

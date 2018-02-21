/*
author: Raupe

task:
4 Echo-Programm (Strings vergleichen)
Das Programm echo.c soll jede eingelesene Zeile sofort wieder ausgeben. Ausgenommen ist nur
eine Zeile mit dem Inhalt QUIT. Bei dieser Zeile soll das Programm sofort stoppen. Hier ein Beispiel
für einen Dialog (Benutzereingaben in Fettdruck):
So
So
ein
ein
Quark
Quark
QUIT
Tschuess!

*/

#include <stdio.h>
#include <string.h>

int main (void)
{
    char input [300] = "";

    while (strcmp (input, "QUIT") != 0)
    {
        printf (input);
        printf ("\n");
        scanf ("%299[^\n]", input);
        while (getchar() != '\n');
        
    }
    printf ("Tschuess");
}
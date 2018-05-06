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
#include <locale.h>
#include <time.h>

int main (void)
{
    char input [300] = "";
    int i;
    char *p;

    setlocale(LC_ALL, "de_DE");

    while (strcmp (input, "QUIT") != 0)
    {
        printf (input);
        printf ("\n");
        p = input;
        while (*p != '\0')
        {
            printf("-%i-", *p);
            p++;
        }
            printf("|%c|", 59);
        printf ("\n");
        scanf ("%299[^\n]", input);
        while (getchar() != '\n');  //Puffer leeren
        
    }
    printf ("Tschüss");

   time_t currtime;
   struct tm *timer;
   char buffer[80];

   time( &currtime );
   timer = localtime( &currtime );

    printf("Locale is: %s\n", setlocale(LC_ALL, "de_DE"));
    strftime(buffer,80,"%c", timer );
    printf("Date is: %s\n", buffer);

    for (i = 0; i < 128; i++)
        putchar(-i);

}
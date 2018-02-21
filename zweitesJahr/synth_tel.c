/* 
author: Raupe

task:
3 Telefonnummer erstellen
Ein Programm synth_tel.c soll zuerst die Vorwahl und die Durchwahl einer Telefonnummer
erfragen. Anschlieÿend soll es die Gesamtnummer in der Form (Vorwahl) Durchwahl erstellen
und zum Schluss ausgeben. Bei leerer Vorwahl soll "05231" als Vorwahl angenommen werden.
Beispiel für einen Dialog (Benutzereingabe in Fettdruck):
Vorwahl..: 0521
Durchwahl: 68000
Ergebnis: (0521) 68000

*/
#include <stdio.h>
#include <string.h>

int main (void)
{
    char vorw [10];
    char nummer [50];
    char ges [60];

    printf ("Vorwahl:\n");
    scanf ("%9[^\n]", vorw);

    printf ("Durchwahl:\n");
    scanf ("%49s", nummer);

    if (strcmp (vorw, "")== 0)
        strcpy (vorw, "05231");

    strcpy (ges, vorw);
    strcat (ges, " ");
    strcat (ges, nummer);

    printf (ges);
}
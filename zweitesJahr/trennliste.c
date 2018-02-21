/*
author: Raupe

task:
C4CA 8)
Im Programm trennliste.c gibt der Benutzer eine durch Doppelpunkt getrennte Liste von
Dingen ein (maximal 800 sichtbare Zeichen). Das Programm soll die Liste zerteilen und die Elemente
einzeln ausgeben. Hier ein Beispiel:
jk@r155pc1:˜$ trennliste
Ihre Eingabe: Pfeffer:Zwiebeln:Gelbe Paprika:Reis:Erbsen
Elemente:
Pfeffer
Zwiebeln
Gelbe Paprika
Reis
Erbsen
*/

#include <stdio.h>
#include <string.h>

int main (void) 
{
    char arr[801] = "";
    char *p;
    printf("Ihre Eingabe: ");
    scanf("%800[^\n]", arr);

    p = strtok(arr, ":");
    while (p != 0)
    {
        printf("%s\n", p);
        p = strtok(NULL, ":");
    }
        
}
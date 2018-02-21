/*
author: Raupe

task:

5 Zusammenbau einer Wortliste
Das Programm wortliste1.c soll jedes Wort (durch Leerzeichen, Tabulator usw. getrennt), das
vom Benutzer eingegeben wird, an einen String mit maximal 80 sichtbaren Zeichen anhängen. Zu
Beginn soll der String leer sein. Sobald das Wort QUIT eingegeben wird, soll die Liste beendet
werden. Zwischen zwei Worten sollen jeweils ein Komma und ein Leerzeichen stehen. Zum Schluss
soll die Wortliste ausgegeben werden. Hier ein Beispiel:
jk@r155pc1:˜$ wortliste
Eingabe: Hund Katze Maus QUIT
Wortliste: Hund, Katze, Maus
a) Erstellen Sie das Programm wortliste1.c! Zunächst soll nicht überprüft werden, ob die
maximale Stringlänge überschritten wird ().
b) Im Programm wortliste2.c soll sichergestellt sein, dass die maximale Stringlänge nicht
überschritten wird. Es soll aber auch kein Wort abgeschnitten werden. Stattdessen soll dann,
wenn ein Wort nicht mehr in den String passt, das Programm wie bei der Eingabe des Wortes
QUIT beendet und vorher die Wortliste (natürlich ohne das überzählige Wort) ausgegeben
werden.

*/

#include <stdio.h>
#include <string.h>

int main (void)
{
    char input [300] = "";
    int i = 0;

    while (strcmp (input, "QUIT") != 0)
    {
        scanf ("%299[^\n]", input);
        while (getchar() != '\n');
        while (input [i] != '\0')
        {
            if (input [i] == ' ')
                
        }
        
    }
    printf ("Tschuess");
}
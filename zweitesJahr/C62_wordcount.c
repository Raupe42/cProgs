/*
author: Raupe

task:
Das Programm wordcount.c soll die Worte einer Datei z¨ahlen.1 Als Wort dient jede Ansammlung
von Zeichen, die durch ein oder mehrere Leerzeichen, Tabulatoren oder Zeilenumbruche ge- ¨
trennt ist.
a) Versuchen Sie zuerst, die Worte in einer Zeichenkette zu z¨ahlen. Dazu kann das folgende
Zustandsdiagramm helfen:
Wort Zwischenraum
Buchstabe
Leerzeichen
Buchstabe Leerzeichen
++wortzahl
b) Jetzt k¨onnen Sie mit getchar() die Zeichen von der Tastatur einlesen und in diesem
Datenstrom die Worte z¨ahlen.
c) Im letzten Schritt lesen Sie mit fgetc() die Zeichen aus einer Datei ein.

*/

//defines
//END_defines

//includes
#include <stdio.h>
//END_includes

//structs
//END_structs

//prototypes
//END_prototypes

/*no global variables*/

int main(void)
{
    FILE *data;
    char path[256];
    int readChar, i = 0;

    printf("Welche Datei?\n");
    scanf("%s", &path);
    data = fopen (path, "r");
    if (!data)
    {
        perror(path);
        return 1;
    }

    readChar = fgetc(data);

    while (readChar != EOF)
    {
        if (readChar < '!') // Leerzeichen usw sind 32 und kleiner
        {
            i++;
            readChar = fgetc(data);
            while (readChar != EOF && readChar < '!')
            {
                readChar = fgetc(data);
            }
        }
        else 
        {
            readChar = fgetc(data);
        }
    }
    

        printf("%i", i);

    return 0;
}
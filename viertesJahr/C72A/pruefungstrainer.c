/*
Pruefungstrainer

Dies ist die gesamte AUfgabe als ein Programm.
Zum compilieren lediglich diese Datei mit gcc aufrufen.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ANZAHL 200

typedef char t_fragefeld[][2][81];

//Prototypen
unsigned short int feld_laden(char fragefeld[][2][81]);
short int eineFrageStellen(short int eintrNr, t_fragefeld fragefeld);
short int feld_laden_aus_datei(char dateiname[80], t_fragefeld feld);

void clearScreen();
//END_Prototypen

int main(void)
{
    short int anzahl = 0;
    int i, input = -1;
    char fragefeld[MAX_ANZAHL][2][81], dateiname[100] = "Fragen.txt";
    FILE *file;
    while (input)
    {
        clearScreen();
        printf("Pruefungstrainer:\n0 Ende\n1 Quiz komplett\n2 Quiz random\n3 Datei laden\n9 Sonder\n");
        printf("Es sind %i Fragen geladen\n", anzahl);
        scanf("%i", &input);
        while (getchar() != '\n')
        {
        };
        switch (input)
        {
        case 1:
            for (i = 0; i < anzahl; i++)
                eineFrageStellen(i, fragefeld);
            break;
        case 2:
            srand(time(NULL));
            eineFrageStellen(rand() % anzahl, fragefeld);
            break;
        case 3:
            anzahl = feld_laden_aus_datei(dateiname, fragefeld);
            clearScreen();
            printf("Es wurden %i Fragen geladen\n", anzahl);
            break;
        case 9:
            while (input)
            {
                clearScreen();
                printf("1 vordefinierte Fragen einlesen\n");
                printf("2 bestimme Frage stellen\n");
                printf ("0 Ende");
                scanf("%i", &input);
                while (getchar() != '\n')
                {
                };
                switch (input)
                {
                case 1:
                    anzahl = feld_laden (fragefeld);
                    break;
                case 2:
                    scanf("%i", &input);
                    while (getchar() != '\n');
                    eineFrageStellen (input, fragefeld);
                    break;
                case 3:
                   
                    break;
                default:
                    break;
                }
               
            }
             input = -1;
        }
    }
    return 0;
}

unsigned short int feld_laden(char fragefeld[][2][81])
{
    int i = 0;
    strcpy(fragefeld[i][0], "Welcher Buchstabe kommt nach A?");
    strcpy(fragefeld[i][1], "B");
    i++;
    strcpy(fragefeld[i][0], "Welcher Buchstabe kommt nach B?");
    strcpy(fragefeld[i][1], "C");
    i++;
    strcpy(fragefeld[i][0], "Welcher Buchstabe kommt nach C?");
    strcpy(fragefeld[i][1], "D");
    i++;
    strcpy(fragefeld[i][0], "Welcher Buchstabe kommt nach D?");
    strcpy(fragefeld[i][1], "E");
    i++;
    return i;
}

/*
    Returns: 1 richtig, 0 FALSCH
*/
short int eineFrageStellen(short int eintrNr, t_fragefeld fragefeld)
{
    char antw[81], tmp, tmpStr [81];
    short int falsch = 1;
    char command[80], *pSTr;
    FILE *output;
    //prüfen ob die Frage erst noch generiert werden muss
    if (fragefeld[eintrNr][0][0] == '#')
    {
        //printf ("strat\n");
        pSTr = strtok(fragefeld[eintrNr][0], "#");
        strcpy(command, "gcc ");
        strcat(command, strtok(pSTr, "\n"));
        strcat(command, " -o extraProg.exe");
        system(command);
        //system ("extraProg.exe");   //.\extraProg.exe > test.txt
        output = _popen("extraProg.exe", "r");
        fgets(fragefeld[eintrNr][0], 80, output);
        fragefeld[eintrNr][0][strlen(fragefeld[eintrNr][0]) - 1] = '\0'; //\n weg
        fgets(fragefeld[eintrNr][1], 80, output);
        strtok(fragefeld[eintrNr][1], "\n"); //\n weg alternativ
        _pclose(output);
    }

    //zu einem Eintrag Frage stellen
    printf("Frage%i: %s\n", eintrNr, fragefeld[eintrNr][0]);

    //Antwort einlesen
    fgets (antw, 80, stdin);
    antw [strlen (antw) -1] = '\0';
    //vergleichen
    falsch = strcmp(fragefeld[eintrNr][1], antw);
    //Wenn Richtig mitteilen sonst korrekt hinschreiben
    if (!falsch)
        printf("ok\n");
    else
        printf("Nope: %s\n", fragefeld[eintrNr][1]);
    return !falsch;
}

//Returns >0 ok-anzhal der Eintraege , -1 Error
short int feld_laden_aus_datei(char dateiname[80], t_fragefeld feld)
{
    FILE *file;
    char buff[81];
    int i = 0, j = 0, len;
    //Textdatei öffnen
    file = fopen(dateiname, "r");
    if (!file)
        return -1;
    //Fragezeile dann Antwortezeile laden
    while (fgets(buff, 80, file) != NULL && i < 200)
    {
        strtok(buff, "\n");
        strcpy(feld[i][j], buff);
        //printf ("Schreibe %s in Feld [%i] [%i] (%i)\n", buff, i, j, len);
        if (j)
        {
            j = 0;
            i += 1;
        }
        else
            j = 1;
    }
    fclose(file);
    //Fehler ggf melden
    return i;
}

void clearScreen()
{
    printf("Enter...\n");
    getchar();
    system("cls");
    return;
}
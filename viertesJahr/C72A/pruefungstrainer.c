/*
Pruefungstrainer

Dies ist die gesamte Aufgabe als ein Programm.
Zum compilieren lediglich diese Datei mit gcc aufrufen.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef UNIX
#define CLS "clear"
#define PFIX "out"
#define POPEN popen
#define PCLOSE pclose
#elif unix
#define CLS "clear"
#define PFIX "out"
#define POPEN popen
#define PCLOSE pclose
#else
#define CLS "cls"
#define PFIX "exe"
#define POPEN _popen
#define PCLOSE _pclose
#endif

#define MAX_ANZAHL 200
#define RICHTIGE_ANTWORT "Richtige Antwort"
#define FALSCHE_ANTWORT "Nicht ganz Richtig"    //<Text>: Loesung
#define DATEINAME "Fragen2.txt"  //zur Eingabe des Dateinamens zur Laufzeit: Zeile auskommentieren

typedef char t_fragefeld[][2][81];
typedef struct statistik_struct {
    int anzahlGestellt;
    int anzahlRichtig;
} t_statistik;

//Prototypen
unsigned short int feld_laden(char fragefeld[][2][81]);
short int eineFrageStellen(short int eintrNr, t_fragefeld fragefeld);
short int feld_laden_aus_datei(char dateiname[80], t_fragefeld feld);
short debugMenu(t_fragefeld fragefeld, short *p_anzahl);
short eineFrageErzeugen (char *target, char *frage, char *antwort);

void clearScreen();
//END_Prototypen

int main(void)
{
    short int anzahl = 0, antwortRichtig;
    int i, input = -1;
    char fragefeld[MAX_ANZAHL][2][81], dateiname[100] = DATEINAME;
    t_statistik statistik;
    while (input)
    {
        clearScreen();
        printf("Pruefungstrainer:\n0 Ende\n1 Quiz komplett\n2 Quiz random\n3 Datei laden\n9 Sonder\n");
        printf("--Es sind %i Fragen geladen--\n", anzahl);
         if (statistik.anzahlGestellt)
                printf ("Bisher wurden %2.1lf%% der Fragen richtig beantwortet.\n", 100.0 * statistik.anzahlRichtig / statistik.anzahlGestellt);
        scanf("%i", &input);
        while (getchar() != '\n')
        {
        };
        switch (input)
        {
        case 1:
            for (i = 0; i < anzahl; i++)
            {
                antwortRichtig = eineFrageStellen(i, fragefeld);
                statistik.anzahlGestellt ++;
                if (antwortRichtig)
                    statistik.anzahlRichtig ++;
            }
            break;
        case 2:
            srand(time(NULL));
            if (anzahl)
            {
                antwortRichtig = eineFrageStellen(rand() % anzahl, fragefeld);
                statistik.anzahlGestellt ++;
                if (antwortRichtig)
                    statistik.anzahlRichtig ++;
            }
            else
                printf ("Bitte erst Frage einlesen...\n");
            break;
        case 3:
            #ifndef DATEINAME
                strcpy (dateiname, "");
                printf ("Bitte den Dateinamen eingeben:\n");
                scanf ("%s", dateiname);
                 while (getchar()!= '\n');
            #endif
            printf ("Lade Daten aus %s\n", dateiname);
            anzahl = feld_laden_aus_datei(dateiname, fragefeld);
            clearScreen();
            printf("Es wurden %i Fragen geladen\n", anzahl);
            break;
        case 9:
            input = debugMenu(fragefeld, &anzahl);
            input = -1;
        }
    }
    return 0;
}

short debugMenu(t_fragefeld fragefeld, short *p_anzahl)
{
    int input;
    short anzahl = *p_anzahl;
    while (input)
    {
        clearScreen();
        printf("1 vordefinierte Fragen einlesen\n");
        printf("2 bestimme Frage stellen\n");
        printf("0 Ende");
        scanf("%i", &input);
        while (getchar() != '\n')
        {
        };
        switch (input)
        {
        case 1:
            anzahl = feld_laden(fragefeld);
            break;
        case 2:
            printf ("Welche Frage soll gestellt werden?\n");
            scanf("%i", &input);
            while (getchar() != '\n')
                ;
            eineFrageStellen(input, fragefeld);
            break;
        case 3:

            break;
        default:
            break;
        }
    }
    *p_anzahl = anzahl;
    return input;
}

/*
Laedt eine Reihe vorgefertigter Fragen
*/
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
    char antw[81];
    short int falsch = 1;
    //prüfen ob die Frage erst noch generiert werden muss
    if (fragefeld[eintrNr][0][0] == '#')
        eineFrageErzeugen (strtok (fragefeld [eintrNr] [0], "#"), fragefeld [eintrNr] [0], fragefeld [eintrNr] [1]);
    //zu einem Eintrag Frage stellen
    printf("Frage%i: %s\n", eintrNr, fragefeld[eintrNr][0]);
    //Antwort einlesen
    fgets(antw, 80, stdin);
    antw[strlen(antw) - 1] = '\0';
    //vergleichen
    falsch = strcmp(fragefeld[eintrNr][1], antw);
    //Wenn Richtig mitteilen sonst korrekt hinschreiben
    if (!falsch)
        //printf("ok\n");
        printf("%s\n", RICHTIGE_ANTWORT);
    else
        //printf("Nope: %s\n", fragefeld[eintrNr][1]);
        printf("%s: %s\n", FALSCHE_ANTWORT, fragefeld[eintrNr][1]);
    return !falsch;
}

//Returns >0 ok-anzhal der Eintraege , -1 Error
short int feld_laden_aus_datei(char dateiname[80], t_fragefeld feld)
{
    FILE *file;
    char buff[81];
    int i = 0, j = 0;
    //Textdatei öffnen
    file = fopen(dateiname, "r");
    if (!file)
    {
        printf ("%s: nicht gefunden oder Ressource ist bereits belegt!\n", dateiname);
        return -1;
    }
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

short eineFrageErzeugen (char *target, char *frage, char *antwort)
{
    char command [80];
    FILE *output;
        strcpy (command, "gcc ");
        strcat (command, strtok (target, "\n"));
        strcat (command, " -o extraProg.");
        strcat (command, PFIX);
        system (command);
        strcpy (command, "");
        #ifdef UNIX
            strcat (command, "./");
        #elif unix
            strcat (command, "./");
        #endif
        strcat (command, "extraProg.");
        strcat (command, PFIX);
        output = POPEN (command, "r");
        fgets (frage, 80, output);
        frage [strlen (frage) - 1] = '\0';
        fgets (antwort, 80, output);
        strtok (antwort, "\n");
        PCLOSE (output);
    return 0;
}

void clearScreen()
{
    printf("Enter...\n");
    getchar();
    system(CLS);
    return;
}
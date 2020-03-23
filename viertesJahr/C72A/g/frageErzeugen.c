#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

//aus e
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

//FUER f
short int feld_laden_aus_datei (char dateiname [80], t_fragefeld feld);
//END_FUER f

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

/*
    Returns: 1 richtig, 0 FALSCH
*/
short int eineFrageStellen (short int eintrNr, t_fragefeld fragefeld )  //ANPASSUNG für g
{
    char antw [81];
    short int falsch = 1;
    char msg [100];

    //prüfen ob die Frage erst noch generiert werden muss
    if (fragefeld [eintrNr] [0] [0] == '#')
        eineFrageErzeugen (strtok (fragefeld [eintrNr] [0], "#"), fragefeld [eintrNr] [0], fragefeld [eintrNr] [1]);

    //zu einem Eintrag Frage stellen
    printf ("Frage%i: %s\n", eintrNr, fragefeld [eintrNr] [0]);

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
    //anzahl = feld_laden (fragefeld);
    anzahl = feld_laden_aus_datei ("Fragen.txt", fragefeld);
    //srand (time(NULL));
    //    eineFrageStellen (rand()%anzahl, fragefeld);
    eineFrageStellen (0, fragefeld);
    return 0;
}

//END_aus e


//Returns >0 ok-anzhal der Eintraege , -1 Error
short int feld_laden_aus_datei (char dateiname [80], t_fragefeld feld)
{   
    FILE *file;
    char buff  [81];
    int i = 0, j = 0, len;
    //Textdatei öffnen
    file = fopen (dateiname, "r");
    if (!file)
        return -1;
    //Fragezeile dann Antwortezeile laden
    while (fgets (buff, 80, file) != NULL && i < 200)
    {
            strtok (buff, "\n");
            strcpy (feld [i] [j], buff);
            //printf ("Schreibe %s in Feld [%i] [%i] (%i)\n", buff, i, j, len);
            if(j)
            {
                j = 0;
                i +=1;
            }
            else
                j = 1;
           
    }
    fclose (file);
    //Fehler ggf melden
    return i;
}
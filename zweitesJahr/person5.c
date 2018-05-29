/*
author: Raupe

task: 
Personliste verwalten

*/

//defines
#define kZahl 20
//END_defines

//includes
#include <stdio.h>
#include <string.h>
//END_includes

//structs
struct persontyp {
    char vorname [30];
    char nachname [30];
    unsigned long gebDat;
    short valid;    //1 valid, 0 invalid
};
//END_structs

//prototypes
void menuetextAusgabe ();
//END_prototypes

/*no global variables*/

int main (void)
{
    //local Var
    int i;
    int input = -1;
    struct persontyp ktabelle [kZahl] = {"", "", 0, 0};
    //init
    do
    {
        menuetextAusgabe ();
        //input lesen
        scanf ("%i", &input);
        //choose
        switch (input)
        {
        case 1:; // Ausgabe aller Daten
        struct persontyp k;
        printf("Alle Daten ausgeben: \n");
        for (i = 0; i < kZahl; i++)
        {
            k = ktabelle [i];
            if (k.valid)
            {
                printf ("%i %s, %s, %ul\n", i, k.nachname, k.vorname, k.gebDat);
            }
        }
            break;
        case 2:;
            //neuen  Daten einlesen
            struct persontyp neu;
            printf ("Vorname: \n");
            scanf ("%29s", &neu.vorname);
            printf ("Nachname: \n");
            scanf ("%29s", &neu.nachname);
            printf ("Genurtstag in yyyymmtt: \n");
            scanf ("%lu", &neu.gebDat);
            neu.valid = 1;

            //leeres Feld suchen
            i = 0;
            while (ktabelle [i].valid && i < kZahl)
            {
                i++;
            }

            if (i < kZahl)
                ktabelle [i] = neu;
            else  
                printf ("Datenbank ist voll!!!\n");
            break;
        case 3:; //Datensatz löschen
            printf ("Lösche Datensatz mit Nr.: \n");
            scanf ("%i", &i);
            ktabelle [i].valid = 0;
            break;
    	case 4:;
            //Vorbelegung erstellen
        struct persontyp n = {"Mensch", "Name", 19960711, 1};
        ktabelle [0] = n;
    
        strcpy (n.vorname, "eine");
        strcpy (n.nachname, "Person");
        n.gebDat = 19930103;
        n.valid = 1;
        ktabelle [2] = n;

        strcpy (n.vorname, "Irgendeine");
        strcpy (n.nachname, "Person");
        n.gebDat = 19917643;
        n.valid = 1;
        ktabelle [3] = n;
        
        strcpy (n.vorname, "Vorname");
        strcpy (n.nachname, "Nachname");
        n.gebDat = 20180529;
        n.valid = 1;
        ktabelle [4] = n;

        break;
        case 0: break;
        default:
        printf ("F  E  H  L  E  R  !\n");
        }
    } while (input != 0);


    printf ("\nEnde\n");
    return 0;
}

void menuetextAusgabe ()
{
    printf ("\n\n0: ENDE\n1: Zeige Alles an\n2: neuer Datensatz\n3: Entferne Daten\n4: Vorbelegen\n");
}
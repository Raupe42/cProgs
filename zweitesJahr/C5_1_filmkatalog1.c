/* 
author: Raupe

task:
C5.1.2
2 Datentyp fur Filmdatenbank ¨
Ein Privatmann m¨ochte seine Filme katalogisieren. Dazu will er fur jeden Film angeben: ¨
• den Filmtitel als Kette von maximal 80 sichtbaren Zeichen
• die Filmdauer in Minuten (0 bis 300 genugt) ¨
• das Jahr, in dem der Film ver¨offentlicht wurde
a) Bitte erstellen Sie den Datentyp struct filmtyp, der diese Anforderungen erfullt! Die ¨
Typen der Komponenten sollen wiederum m¨oglichst genau mit der Praxis ubereinstimmen; ¨
z.B. soll kein negativer Wert fur die Dauer des Films m ¨ ¨oglich sein.
b) Erstellen Sie ein Programm filmkatalog1.c, das fur eine Variable des Typs ¨
struct filmtyp alle Daten von der Tastatur einliest und kurz danach wieder auf dem
Bildschirm ausgibt!
c) Zusatzaufgabe: Zeichnen Sie fur den erstellten Datentyp ein Jackson-Diagramm! 
*/

//defines

//END_defines

//includes
#include <stdio.h>
#include <string.h>
//END_includes

//prototypes

//END_prototypes

//structs
struct filmtyp_t {       //a)
    char filmtitel [81];
    unsigned short filmdauer;
    unsigned int releaseJahr;
};
//END_structs

//no global variables

int main (void)
{
    struct filmtyp_t film;
    printf("Titel:");
    scanf("%80s", film.filmtitel);
    printf("Filmdauer:");
    scanf("%us", &film.filmdauer);
    printf("Erscheinungsjahr:");
    scanf("%ui", &film.releaseJahr);
    printf("\nOUT\n");
    //Ausgabe
    printf("Titel: %s\n", film.filmtitel);
    printf("Filmdauer: %us\n", film.filmdauer);
    printf("Erscehinungsjahr: %ui\n", film.releaseJahr);
    return 0;
}
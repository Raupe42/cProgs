/*
author: Raupe

task:C5.2.1
1 Funktionen fur Regalbretter-Datentyp ¨
Im Beispiel des Holzlagers mussen nun Funktionen geschrieben werden, mit denen auf ein Recor ¨ d
zugegriffen werden kann (regalbrett2.c).
a) Die Funktion
void printbrett(struct regalbrett_t brett)
soll alle Daten eines Records auf den Bildschirm ausgeben.
b) Die Funktion
struct regalbrett_t scanbrett(void)
soll von der Tastatur alle Daten in ein Record einlesen, das an die aufrufende Funktion
zuruckgegeben wird. ¨
c) Die Funktion
void kuerzebrett(struct regalbrett_t* pbrett, unsigned int kuerzg)
soll bewirken, dass die L¨ange des Brettes, auf das pbrett zeigt, um kuerzg Millimeter
verringert wird. Diese Funktion soll aufgerufen werden, wenn ein Brett um ein bestimmtes
Maß gekurzt wurde. ¨
d) Zusatzaufgabe: Die Funktion
struct regalbrett_t leimen(struct regalbrett_t brett_a,
struct regalbrett_t brett_b, int* pfehler)
soll aufgerufen werden, wenn zwei Regalbretter a und b zusammengeleimt wurden, um ein
l¨angeres Brett zu erhalten. Dabei mussten die Breite und die Holzart identisch sein. Das
entstehende l¨angere Brett soll an die aufrufende Funktion zuruckgegeben werden. Falls die ¨
Holzart und die Breite gleich sind, ist das erfolgreich; in diesem Fall soll nach *pfehler
eine Null geschrieben werden, andernfalls eine Eins.

*/

//defines
//END_defines

//includes
#include <stdio.h>
#include <string.h>
//END_includes

//structs
struct regalbrett_t {
    unsigned int breite;
    unsigned int tiefe;
    unsigned int dicke;
    char holzart[25];
};
//END_structs

//prototypes
void printbrett(struct regalbrett_t brett);
struct regalbrett_t scanbrett(void);
void kuerzebrett(struct regalbrett_t *pbrett, unsigned int kuerzg);
struct regalbrett_t leimen(struct regalbrett_t brett_a, struct regalbrett_t brett_b, int *pfehler);
//END_prototypes

/*no global variables*/

int main (void)
{
    struct regalbrett_t brett;
    int i;
    brett = scanbrett();
    printbrett(brett);
    kuerzebrett(&brett, 50);
    printbrett(brett);
    brett = leimen(brett, brett, &i);
    printbrett(brett);
    printf("%i", i);
    return 0;
}


//a)
void printbrett(struct regalbrett_t brett)
{
    printf("OUT:\nBreite: %u\n", brett.breite);
    printf("Breite: %u\n", brett.tiefe);
    printf("Breite: %u\n", brett.dicke);
    printf("Breite: %s\n\n", brett.holzart);
}

//b)
struct regalbrett_t scanbrett (void)
{
    struct regalbrett_t brett;
    printf("Breite: ");
    scanf("%ui", &brett.breite); printf("\n");
    printf("Tiefe: ");
    scanf("%ui", &brett.tiefe); printf("\n");
    printf("Dicke: ");
    scanf("%ui", &brett.dicke); printf("\n");
    printf("Holzart: ");
    scanf("%24s", brett.holzart); printf("\n");

    return brett;
}

//c)
//Das muss auch schöner gehen!!
void kuerzebrett(struct regalbrett_t *pbrett, unsigned int kuerzg)
{
    struct regalbrett_t brett;
    brett = *pbrett;
    if (brett.breite - kuerzg >0)
        brett.breite = brett.breite - kuerzg;
    else
        brett.breite = 0;
    *pbrett = brett;
    return;
}

//d)
//irritation der Aufgabenstellungen: in C5.1 hatte ein Brett BxTxH und hier ??LxBxH 
// => gefordert gleiche Breite wird hier als Tiefe interpretiert
// H wird ignoriert ???
struct regalbrett_t leimen(struct regalbrett_t brett_a, struct regalbrett_t brett_b, int *pfehler)
{
    struct regalbrett_t brett;
    if (strcmp (brett_a.holzart, brett_b.holzart) == 0 && brett_a.tiefe == brett_b.tiefe)
    {
        brett = brett_a;
        brett.breite = brett_a.breite + brett_b.breite;
        *pfehler = 0;
    }
    else
        *pfehler = 1;
    return brett;
}
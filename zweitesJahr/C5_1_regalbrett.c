/* 
author: Raupe

task:
C5.1.1
1 Datentyp fur Regalbretter ¨
In einem Holzlager soll die Erfassung von Brettern automatisiert werden. Zu jedem Brett soll
angegeben werden:
• die Breite in Millimetern, ganzzahlig
• die Tiefe in Millimetern, ganzzahlig
• die Dicke in Millimetern, ganzzahlig
• die Holzart (z.B. Erle) als Kette von maximal 24 sichtbaren Zeichen
a) Bitte erstellen Sie den Datentyp struct regalbrett_t, der diese Anforderungen erfullt! ¨
Die Typen der Komponenten sollen m¨oglichst genau mit der Praxis ubereinstimmen; z.B. soll ¨
kein negativer Wert fur die Breite, Tiefe und Dicke m ¨ ¨oglich sein.
b) Erstellen Sie ein Programm regalbrett1.c, das fur eine Variable des Typs ¨
struct regalbrett_t alle Daten von der Tastatur einliest und kurz danach wieder auf
dem Bildschirm ausgibt!
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
struct regalbrett_t {       //a)
    unsigned long breite;
    unsigned int tiefe;
    unsigned short dicke;
    char holzart[25];
};
//END_structs

//no global variables

int main (void)
{
    struct regalbrett_t brett;
    printf("Breite: ");
    scanf("%ul", &brett.breite); printf("\n");
    printf("Tiefe: ");
    scanf("%ui", &brett.tiefe); printf("\n");
    printf("Dicke: ");
    scanf("%uh", &brett.dicke); printf("\n");
    printf("Holzart: ");
    scanf("%24s", brett.holzart); printf("\n");

    //Ausgabe
    printf("Breite: %ul\n", brett.breite);
    printf("Breite: %ui\n", brett.tiefe);
    printf("Breite: %uh\n", brett.dicke);
    printf("Breite: %s\n", brett.holzart);
    return 0;
}
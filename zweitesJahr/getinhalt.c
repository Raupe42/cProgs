/* 
author: Raupe

task:
C4CA 9
Im folgenden Programm getinhalt.c enthält die Variable arr eine Reihe von Zeigern auf
konstante Zeichenketten der Form Name=Inhalt. Man spricht hier von einem Assoziativen Speicher,
denn zu jedem Inhalt (nach dem Gleichheitszeichen) ist die zugehörige Bedeutung (vor dem
Gleichheitszeichen) vermerkt.
In diesem Fall ist im Namen ein Ländercode nach ISO 3166 (allerdings in Kleinbuchstaben)
angegeben. Im Inhalt ist die Bezeichnung des zugehörigen Landes. Die Funktion get_inhalt()
soll nun zu einem als Parameter übergebenen Namen den entsprechenden Inhalt ausgeben. Falls
nichts gefunden wurde oder falls ein oder mehrere NULL-Zeiger als Parameter übergeben wurden,
soll der Wert NULL zurückgegeben werden.
a) Erstellen Sie diese Funktion!
b) Der Fragezeichen-Operator in Zeile 10 hat nichts mit Zeichenketten zu tun. Was bewirkt er?
c) Falls das Array nach Ländercodes sortiert und die Anzahl der Elemente vorher bekannt ist
- wie kann man dann die Suche beschleunigen?


#i n cl u d e <s t d i o . h>
#i n cl u d e <s t r i n g . h>
char * g e t_i n h al t ( const char * a r r [ ] , const char * such ) ;
int main ( void)
{
const char * a r r []= { "dk=Daenemark" , " i t=I t a l i e n " ,
" l u=Luxemburg" , " nl=Ni e d e rl a n d e " , NULL} ;
char *p ;
p=g e t_i n h al t ( a r r , " nl " ) ;
p r i n t f ( ">>%s<<\n" , p?p : " ni c h t ge funden " ) ;
return 0 ;
}

*/

#include <stdio.h>
#include <stringh.h>

//proto
char *getinhalt(char *, char *);
//protoEnd

int main (void)
{
    const char *arr[] = {"dk = Daenemark", "it = Italien", "lu = Luxemburg", NULL};
    char *p;
    p = getinhalt(arr, "nl");
    printf(">>%s<<\n", p?p : "nicht Gefunden");
    return 0;
}


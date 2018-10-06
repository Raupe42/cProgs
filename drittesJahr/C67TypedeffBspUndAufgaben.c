/*
author: Raupe

Setzt man vor eine Variablen-Vereinbarung das Schlüsselwort typedef erhält man eine Typenvereinbarung
Der neue Typ ist kompatibel zur (bisherigen) Variablen-Vereinbarung.

Beispiel:

bisher:
    int *px;
neu:
    typedef int *pityp;
    pityp px;


*/

#include <stdio.h>

int main (void)
{
    /*
    char s [81];
    char t [81];
    char u [81];
    char v [81];                //v ist eine Variable
    */
    typedef char dt [81];       //dt ist jetzt ein Datentyp
                                //dt ist ein neuer Name für char [81];
                                //
    typedef double doppel;      //jetzt kann doppel anstatt double zur deklaration verwendet werden
    //typedeff ALT NEU

    //auch möglich:
    typedef struct struct_datum //struct_datum kann entfallen
    {
        int t,m,j;
    } datum_t;
    

    //Aufgaben
    //C67A
    //a)
    typedef unsigned short uint16_t;

    //b)
    typedef long double * l_double_ptr_t;

    //c)
    typedef int screen_bitmap_t [600] [800];

    //d)
    typedef struct person_t persontyp;

    //2
    //a)
    typedef int ctype (int);
    ctype tolower;

    //3 a)
    typedef void (*atexithandler_t) (void);
    int atexit (atexithandler_t);


}
/*
_________________________
|     Person             |
|________________________|
| - vorname: char [0..40]|
| - nachname:char [0..40]|
|________________________|
| + void print1 ()       |
| + void print2 ()       |
|________________________|
*/

#include <stdio.h>
#include <string.h>

typedef struct person_struct
{
    char vorname [41];
    char nachname [41];
    int gebDatum; //JJJJMMTT

    void print1 ()
    {
        printf ("%s %s\n", vorname, nachname);
    }
    void print2 ()
    {
        printf ("%s %s\n", nachname, vorname);
    }
}Person;

int main ()

{
    Person pers1;
    strcpy (pers1.vorname, "Vorname");
    strcpy (pers1.nachname, "Nachname");
    pers1.print1 ();
    pers1.print2 ();

}
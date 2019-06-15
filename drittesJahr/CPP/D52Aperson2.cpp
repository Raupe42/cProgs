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

class person_class
{
private:
    char vorname[41];
    char nachname[41];
    int gebDatum; //JJJJMMTT
    
public:
    void init (const char vorn [41], const char nachn [41], const int gebDat)
    {
        strcpy (vorname, vorn);
        strcpy (nachname, nachn);
        gebDatum = gebDat;
    }
    void init ()
    {
        strcpy (vorname, "De");
        strcpy (nachname, "fault");
        gebDatum = 101010;  //basis 2
    }

    bool ist_ok ()
    {
        return true;
    }
    void print1()
    {
        printf("%s %s\n", vorname, nachname);
    }
    void print2()
    {
        printf("%s %s\n", nachname, vorname);
    }

    
};

int main()

{
    person_class pers1;
   // strcpy(pers1.vorname, "Vorname");
   // strcpy(pers1.nachname, "Nachname");
   pers1.init ("Vorname", "Nachname", 20000101);
    pers1.print1();
    pers1.print2();

      pers1.init ();
    pers1.print1();
    pers1.print2();
}
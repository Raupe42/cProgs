# include <stdio.h>
#include <string>

typedef struct datum_str
{
    int tag, monat, jahr;
    void display ()
    {
        printf ("%04i.%02i.%02i\n", jahr, monat, tag);   
    }
    bool is_schaltjahr ()
    {
        bool isSchaltjahr = false;
        if (jahr % 4 == 0)
        {
            isSchaltjahr = true;
            if (jahr %100 != 0)
            {
                if (jahr % 400 != 0)
                isSchaltjahr = false;
            }
        }
        return isSchaltjahr;
    }
    int anzahl_tage ()
    {
        return tag;
    }
    void tag_vor ()
    {
        tag++;
    }
    void tag_zurueck ()
    {
        tag--;
    }
}datum;

int main ()
{
    datum dat1 = {18, 5, 2019};
    dat1.display();
}
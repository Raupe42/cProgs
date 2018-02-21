/* 
author: Raupe

task:
C4BA 7. April 2014
Arbeitsblatt: Ruckgabe von Arrays durch Funktionen ¨
1 itoa()
In manchen C-Umgebungen ist sie vorhanden, aber im Standard fehlt sie: Die Funktion itoa().
Sie wandelt eine int-Zahl in eine Zeichenkette um. Aus der Zahl 2014 wird das char-Array
{’2’, ’0’, ’1’, ’4’, ’\0’} bzw. in Kurzform "2014". Im Innern der Funktion muss
eine Dual- nach Dezimal-Wandlung stattfinden.
Zur Erinnerung: Bei der Dezimal- nach Dual-Wandlung wurde die Ursprungszahl immer wieder
durch zwei geteilt, bis das Ergebnis null war. Die zwischendurch entstandenen Reste bildeten dann
die gesuchte Dual-Darstellung, nur in umgekehrter Reihenfolge:
11(dez.)=1011(dual)
11/2=5 Rest 1
5/2=2 Rest 1
2/2=1 Rest 0
1/2=0 Rest 1
Ebenso kann auch der Computer die Wandlung ins Dezimalsystem vornehmen:
621(dual)=621
621/10=62 Rest 1
62/10=6 Rest 2
6/10=0 Rest 6
Diese (hier drei) Ziffern mussen dann noch einzeln in ASCII-Zeichen ¨ ubersetzt werden und fertig ¨
ist die Umwandlung von int nach char* (o.k., die Terminierung fehlt noch).
a) Erstellen Sie eine Funktion char *beispiela(void), die stets die Zeichenkette "bestanden"
zuruckgibt! Denken Sie daran, den R ¨ uckgabestring als ¨ static-Variable zu deklarieren!
– Test mit printf(beispiela());
b) Erstellen Sie eine Funktion char *beispielb(int z2, int z1, int z0), die aus
den Zahlen z2, z1 und z0 die Ziffernkette macht, die zu 100z2 + 10z1 + z0 passt. Beispiel:
Der Aufruf beispielb(6,2,1) soll als Ergebnis die Zeichenkette "621" liefern. Denken
Sie wieder daran, den Ruckgabestring als ¨ static-Variable zu deklarieren!
c) Erstellen Sie nun eine Funktion void beispielc(unsigned int x), die — wie oben
beschrieben — nacheinander die Zahl x zerlegt und die Ziffern auf den Bildschirm ausgibt.
Der Aufruf beispielc(621) soll als Ergebnis die Ausgabe 1,2,6 haben.
d) Nun ist die Funktion char *beispield(unsigned int x) dran: Auch sie soll die Zahl
x zerlegen. Die Ziffern sollen nun aber nacheinander in einem String abgelegt werden. Damit
dem ASCII-Code Genuge getan wird, muss zu jeder Ziffer 48 hinzugef ¨ ugt werden, damit aus ¨
der ASCII-Nummer 0 die 48 wird (’0’), aus der 1 die 49 (’1’), aus der 2 die 50 (’2’) usw.
Denken Sie daran, den String zu terminieren!
– Test mit: printf(beispield(621);
e) Die Funktion aus der letzten Teilaufgabe gibt den String noch in verkehrter Reihenfolge
wieder. In char *utoa(unsigned int x) soll der String umgedreht werden.
f) In char *itoa(int x) schließlich soll berucksichtigt werden, dass ¨ x auch negativ sein
kann. In dem Fall muss vorher das Zweierkomplement gebildet werden.
– Test mit: printf(itoa(-621);

*/

#include <stdio.h>

//prototypes
char *beispiela();
char *beispielb(int, int, int);
void beispielc(unsigned int);
char *beispield(unsigned int);
char *utoa(unsigned int);
char *itoa(int);

int main (void)
{
    //printf(beispiela());
    //printf(beispielb(6,2,1));
    //beispielc(321);
    //printf (beispield (621));
    //printf(utoa(621));
    printf(itoa(-621));
}

// ******************a)*******************a)*******************a)*******************a)*******************a)
char * beispiela()
{
    static char beispielaStr [80] = "bestanden";
    return beispielaStr;
}

//*******************b)*******************b)*******************b)*******************b)*******************b)
char * beispielb (int z2, int z1, int z0)
{
    static char bString[80];
    bString[0] = (z2 + '0');
    bString[1] = (z1 + '0');
    bString[2] = (z0 + '0');
    return bString;
}

//*******************c)*******************c)*******************c)*******************c)*******************c)
void beispielc (unsigned int x)
{
    static char cStr[80];
    int i;
    for (i = 0; x != 0; i++)
    {
        cStr[i] = ((x % 10) + '1' - 1);
        x = x / 10;
    }
    cStr[i] = '\0';
    printf (cStr);
   
}

//*******************d)*******************d)*******************d)*******************d)*******************d)
char * beispield (unsigned int x) 
{
    static char dStr[80];
    int i;
    for (i = 0; x != 0; i++)
    {
        dStr[i] = ((x % 10) + '1' - 1);
        x = x / 10;
    }
    dStr[i] = '\0';
    return dStr;
}
//*******************e)*******************e)*******************e)*******************e)*******************e)
char * utoa (unsigned int x)
{
    static char eStr[80];
    char temp[80];
    int i, j;
    for (i = 0; x != 0; i++)
    {
        temp[i] = ((x % 10) + '1' - 1);
        x = x / 10;
    }
    i--;
    for (j = 0; i >= 0 ; j ++)
    {
        eStr[j] = temp[i];
        i--;
    }
    return eStr;
}

//*******************f)*******************f)*******************f)*******************f)*******************f)
char * itoa (int x)
{
    static char fStr[80];
    char temp[80];
    int i, j;
    char neg;
    if (x <0)
    {
        x = x * (-1);
        neg = '-';
    }

    for (i = 0; x != 0; i++)
    {
        temp[i] = ((x % 10) + '1' - 1);
        x = x / 10;
    }
    if (neg == '-')
        temp[i] = neg;
    else
        i--;

    for (j = 0; i >= 0 ; j ++)
    {
        fStr[j] = temp[i];
        i--;
    }
    fStr[j] = '\0';
    return fStr;
}

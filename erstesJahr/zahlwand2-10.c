#include <stdio.h>

//author: Raupe

//Task:
/*
4 Zahlenumwandlung von Basis 10 nach Basis 2
a) (zahlwand2.c)
Um eine Zahl (eingegeben z.B. zur Basis 10) im Dualzahlensystem darstellen zu k¨onnen,
ist eine Folge von Divisionen durch 2 notwendig. Mit jeder Division wird eine weitere Ziffer
ermittelt. Die Folge bricht ab, wenn der Rest null ist Schreiben Sie ein entsprechendes Programm!
Hinweis: Die Ausgabe des Programmes darf in umgekehrter Reihenfolge stattfinden;
mit Tricks wie der Verwendung des Backspace-Zeichens (\b) kann man allerdings auch eine
normale Ausgabereihenfolge erreichen.
b) (zahlwand2-10.c)
Erweitern Sie das Programm aus der vorigen Teilaufgabe so, dass statt der festen Basis 2
(Dualzahlen) eine beliebige Basis zwischen 2 und 10 m¨oglich ist!
c) (zahlwand2-36.c)
Erweitern Sie das Programm aus der vorigen Teilaufgabe so, dass jetzt die Umwandlung in
eine beliebige Basis zwischen 2 und 36 m¨oglich ist! Ziffern zwischen 10 und 35 sollen durch
die Buchstaben A bis Z dargestellt werden.
*/


int main (void)
{
    //VarDef
    int inputInt, wert, out [32], i, base;
    //VarInit
    inputInt = 0;
    wert = 0;
    i = 0;
    base = 2;
    for (i = 0; i <32; i++)
        out [i] = -1;

    //Intro + Input
    printf ("Wandel von Basis 10 in eine andere \n");
    printf ("Bitte eine Zahl zur Basis 10 eingeben:\n");

    scanf ("%i", &inputInt);

    printf ("Zielbasis zwischen 2 und 10:\n");
    scanf ("%i", &base);

    wert = inputInt;
    //Calc + out
    i = 0;
    while (wert != 0)
    {
        printf ("%i", wert%base);
        out [i] = wert%base;
        wert = wert - wert%base ;
        wert = wert /base ;
        i++;
    }
    printf ("\njetzt richtig herum\n");
    for (i = 31; i >= 0; i--)
    {
        if (out [i] >= 0)
            printf ("%i", out [i]);
        if (i%4 == 0 && out [i] >= 0)
            printf (" ");
    }
}
/*
author: Raupe

Task:
C43A
Nr. 1b
mit random Temp
und Negativ
*/

//includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Proto
int rndm_int(int maxVal);
void printBalken(int l, char sign);
void erfasseTemp(int *pArr);

//Prog
int main(void)
{
    //Random Init
    srand(time(0));

    //End Random Init
    int i;
    int Werte[24];
    char sign = '0';

    erfasseTemp(Werte);

    //Ausgabe
    printf("Temp:");
    for (i = 0; i < 24; i++)
    {
        printf(" %i,", Werte[i]);
    }
    printf("\n");

    //Eigentliche Aufgabe:
    for (i = 0; i < 24; i++)
    {
        printf("%i:00 ", i);
        if (Werte[i]< 0)
            sign = '-';
        else 
            sign = '+';
        printBalken(Werte[i], sign);
        printf("\n");
    }

}

//Hilfsfunktionen
int rndm_int(int maxVal)
{
    unsigned int x;
    x = (rand() % maxVal);
}

void printBalken(int l, char sign)
{
    int i;
    //negative Länge geht ja nicht; dann *-1
    if (l < 0)
        l = -l;
    for (i = 0; i < l; i++)
    {
        printf("%c", sign);
    }
}

void erfasseTemp(int *pArr)
{
    //printf ("%i", *(pArr));   //Zugriff auf das erste Element des Array
    int i;
    // Werte = pArr;
    *pArr = rndm_int(5);       //Feld 0, Start Temp
    for (i = 1; i < 24; i++)
    {
        // Werte[i] = Werte[i - 1] + (rndm_int(5) - 3);
        *(pArr + i) = *(pArr + i - 1) + (rndm_int(5) - 2);
    }
}
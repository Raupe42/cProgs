/*
author: Raupe

Task:
C43A

mit random Temp

*/

//includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Proto
int rndm_int(int maxVal);
void printBalken(int l);
void erfasseTemp(int *pArr);
//void WerteFuellen (int *Arr, int ArrLgth);

//Prog
int main(void)
{
    //Random Init
    srand(time(0));
    //End Random Init
    int i;
    int Werte[24];
    //  WerteFuellen

    erfasseTemp(Werte);
    /*
  for (i = 0; i < 24; i++)
  {
      Werte [i] = rndm_int (40);
  }
*/
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
        printBalken(Werte[i]);
        printf("\n");
    }

    //   erfasseTemp(Werte);
}

/*
void WerteFuellen (int *Arr, int ArrLgth)
{
    int i;
    int LokalArr [24];
    &LokalArr = Arr;
    for (i = 0; i < ArrLgth; i++)
    {
        LokalArr[i] = 1;
    }
}
*/

//Hilfsfunktionen
int rndm_int(int maxVal)
{
    unsigned int x;
    x = (rand() % maxVal);
}

void printBalken(int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        printf("*");
    }
}

void erfasseTemp(int *pArr)
{
    //printf ("%i", *(pArr));   //Zugriff auf das erste Element des Array
    // int Werte[24];
    int i;
    // Werte = pArr;
    *pArr = rndm_int(30);
    for (i = 1; i < 24; i++)
    {
        // Werte[i] = Werte[i - 1] + (rndm_int(5) - 3);
        *(pArr + i) = *(pArr + i - 1) + (rndm_int(5) - 3);
    }
}
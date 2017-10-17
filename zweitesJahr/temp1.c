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
int rndm_int (int maxVal);
void printBalken (int l);
//void WerteFuellen (int *Arr, int ArrLgth);

//Prog
int main (void)
{
    //Random Init
    srand (time(0));
    //End Random Init
    int i;
    int Werte [24];
  //  WerteFuellen
  for (i = 0; i < 24; i++)
  {
      Werte [i] = rndm_int (40);
  }

  //Ausgabe
  printf("Temp:");
  for (i = 0; i < 24; i++)
  {
      printf (" %i,", Werte [i]);
  }
  printf ("\n");
  for (i = 0; i < 24; i++)
  {
      printf ("%i:00 ", i);
      printBalken (Werte[i]);
      printf ("\n");
  }

    
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
int rndm_int (int maxVal)
{
    unsigned int x;
    x = (rand () % maxVal);
}

void printBalken (int l)
{
    int i;
    for (i = 0; i < l; i++)
    {
        printf ("*");
    }
}
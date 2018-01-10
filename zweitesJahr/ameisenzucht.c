/*
author: Raupe

Aufgabe: C45A2
*/

#define y_max 13
#define x_max 20
#define tot_bei 3
#define min_pop 2
#define max_pop 6
#define debug 1
#define comp 1

#include <stdio.h>
#include <stdlib.h>

void consoleRefresh();

int main (void)
{
    //dec
    int Feld [x_max][y_max] = {{1,0,1}};
    int nachbarnFeld [x_max] [y_max];
    int altFeld [x_max] [y_max];
    int x, y, xl, yl, xu, yu; //laufindizees, l -> index -1 , u index +1
    int nachbarn;
    char input = 'a';
    consoleRefresh();
    printf ("Enter fuer naechste Stufe, 0 zum beenden");
    // Dauerschleife
    //Erste Ausgabe
     for (x = 0; x < x_max; x++)
            {
                for (y = 0; y < y_max; y++)
                {
                    printf (" %i ", Feld [x][y]);
                }
                printf (".%i\n", x);
            }
    while (input != '0')
    {
        input = getchar();
        //Eine Evolutionsstufe weiter
        if (input == '\n')
        {
            //INIT 
            /*
             for (x = 0; x < x_max; x++)
            {
                for (y = 0; y < y_max; y++)
                {
                   Feld [x][y] = 0;
                }
            }
            Feld [0] [1] = 1;
            */
            //für das ganze Spielfeld
            for (x = 0; x < x_max; x++)
            {
                for (y = 0; y < y_max; y++)
                {
                    //Abfragen durchführen -> Feld als Kugel
                    xl = x -1;
                    xu = x + 1;
                    yl = y - 1;
                    yu = y + 1;
                    if (x <= 0)
                        xl = (x_max - 2);
                    if (x >= x_max -1)
                        xu = 0;
                    if (y <= 0)
                        yl = (y_max - 2);
                    if (y >= y_max - 1)
                        yu = 0;

                    nachbarn = 0;

                   // printf ("%i %i %i %i %i %i", x, y, xl, yl, xu, yu);
                    //Felder im Kreis von O_O auswerten
                    nachbarn = nachbarn + Feld [xl][y];
                    nachbarn = nachbarn + Feld [xl][yu];
                    nachbarn = nachbarn + Feld [x][yu];
                    nachbarn = nachbarn + Feld [xu][yu];
                    nachbarn = nachbarn + Feld [xu][y];
                    nachbarn = nachbarn + Feld [xu][yl];
                    nachbarn = nachbarn + Feld [x][yl];
                    nachbarn = nachbarn + Feld [xl][yl];
                   // printf("");
                   nachbarnFeld [x] [y] = nachbarn;
                   //alten Wert merken
                   altFeld [x] [y] = Feld [x] [y];
                    //vermehren?
                    if (nachbarn >= min_pop && nachbarn <= max_pop)
                        Feld[x][y] = 1;
                        //verhungern?
                    else if (nachbarn >= tot_bei)
                        Feld [x] [y] = 0;
                    else
                        if (debug)
                        printf ("\n %i %i %i\n %i %i %i\n", xl, x , xu, yl, y, yu)    ;
                    
                }
            }
            //Ausgabe
           // consoleRefresh();
           //printf ("start");
            for (x = 0; x < x_max; x++)
            {
                for (y = 0; y < y_max; y++)
                {  
                    if (debug)
                        printf ("| %i (%i) |", Feld [x][y], nachbarnFeld[x][y]);
                    else if (comp)
                        if (Feld [x] [y] == altFeld [x][y])
                            printf (" %i ", Feld [x][y]);
                        else 
                            printf ("|%i|", Feld [x][y]);
                    else
                        printf (" %i ", Feld [x][y]);
                }
                printf (".%i\n", x);
            }
            printf ("________-----------___________-------------_____________-----------\n");

        }
    }

}

void consoleRefresh()
{
     system("@cls||clear");
}
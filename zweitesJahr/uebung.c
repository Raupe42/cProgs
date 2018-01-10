#include <stdio.h>

double messwerte (int);


int main (void){
    int arr [4] = {0,1,2};
    printf ("%i %i %i %i", arr[0], arr[1], arr[2], arr[3]);
}

double messwerte (int x){
    //Auswahl aus 10 Messwerten

    double ergebnis;
    switch (x) {
        case 0: 
        ergebnis = 12.4;
        break;

        case 1:
        ergebnis = 23.6;
        break;
        
        default:
        ergebnis = 0.0;
    }
    return ergebnis;
}

void strTest ()
{
    char str [20]= "";

    scanf("%19[^A]");
}
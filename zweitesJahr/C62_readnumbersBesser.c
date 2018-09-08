/*
author: Raupe

task:

*/

//defines
//END_defines

//includes
#include <stdio.h>
#include <string.h>
//END_includes

//structs
//END_structs

//prototypes
//END_prototypes

/*no global variables*/

int main(void)
{
    FILE * data;
    char input [256];
    double value, sum, avg, min, max;
    double storage [1000] = {0.0};
    int i = 0, n;

    printf ("Bitte Datei eingeben: \n");
    scanf ("%s", &input);

    data = fopen (input, "r");
    if (!data)
    {
        perror (input);
        return 1;
    }

   // fgets (input, 256, data);
    while (fgets (input, 256, data) != NULL)
    {
        sscanf (input,"%lf", &value);
        storage [i] = value;
        i++;
        //fgets (input, 256, data);
    }

    fclose (data);

    for (n = 0; n < i; n++)
    {
        sum += storage [n];
    }
    avg = sum / n;
    min = storage [0];
    for (n = 0; n < i; n++)
    {
        if (min > storage [n])
            min = storage [n];
    } 
    max = storage [0];
    for (n = 0; n < i; n++)
    {
        if (max < storage [n])
            max = storage [n];
    } 

    printf ("\nAVG: %lf, MIN: %lf, MAX: %lf\n", avg, min, max);
}
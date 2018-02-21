/*
author: Raupe

task:

eingaben von quelle und ziel (je [10])
ausgabe qelle + ziel
*/

#include <stdio.h>
#include <string.h>

#define LENGTH 5   //max uInt

/*
oder 
define len 10

define xstr(x) #x
define str(x) xstr(x)

scanf ("%" xstr(len) "[^\n]", out);
*/

//proto
char * utoa (unsigned int x);

//protoEnd

int main (void)
{
    char z [LENGTH], q [LENGTH];
   
   // maxLen berechnen und scanf String zusammenbauen
    char tempC [2];
    char maxLen [20] = "%";     
    char end [] = "[^\n]";
    
    strcat (maxLen, utoa (LENGTH-1));
    strcat (maxLen, end);
    //ende maxLen berechnen
    
    scanf (maxLen, q);
    while (getchar () != '\n' );
    scanf (maxLen, z);
    while (getchar () != '\n' );

    strncat (q, z, LENGTH - 1- strlen(q));

    printf ("%s", q);
}

char * utoa (unsigned int x)
//aus itoa.c gem C4BA 1e) 
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

/*
Arbeiten Sie zunächst mit der Zeichenkette:
char zk[]="www-data:x:33:33:www-data:/var/www:/bin/sh";
Entwickeln Sie mit Hilfe von strtok() eine Funktion p=str_holen1(s,n), die Ihnen
aus der Zeichenkette s den n-ten Teilstring herausholt und die Startadresse an p übergibt.
*/

#include <stdio.h>
#include <string.h>

char *str_holen1 (char *s, int n)
{
    int i;
    char *retVal;
    retVal = strtok (s, ":");
  
    for (i = 1; i < n; i++)
    {
        retVal = strtok (NULL, ":");
    }
    return retVal;
}


int main (void)
{
    char zk [] = "www-data:x:33:33:www-data:/var/www:/bin/sh";
    char *p;

    p = str_holen1 (zk, 1);
    printf ("%s\n",p);

}
/*
Leider zerstört strtok() die Zeichenkette unwiederbringlich. Deswegen sollen Sie nun eine
neue Funktion p=str_holen2(s,n) schreiben.
Diese Funktion soll Ihnen genauso den nten Teilstring liefern. 
Sie soll allerdings kein strtok() enthalten. Stattdessen können Sie das
Trennzeichen mit strchr()) suchen. Oder sie können von Hand den String durchsuchen
oder eine andere Funktion nehmen. Damit Sie die originale Zeichenkette nicht zerstören
müssen, soll das Ergebnis in eine andere Variable kopiert werden. Dazu benutzen Sie bitte
die Funktion malloc(). Vergessen Sie nicht, das Ergebnis zu terminieren
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str_holen1(char *s, int n)
{
    int i;
    char *retVal;
    retVal = strtok(s, ":");

    for (i = 1; i < n; i++)
    {
        retVal = strtok(NULL, ":");
    }
    return retVal;
}

char *str_holen2(char *s, int n)
{
    char *retVal, *pStr;
    int i;
    pStr = s;
    if (n)
    {
        pStr = strchr(s, ':');
        for (i = 1; i < n; i++)
            pStr = strchr(pStr + 1, ':');
        pStr++;
    }
    
    i = 0;
    while (*(pStr + i) != ':' && *(pStr + i) != '\0')
        i++;    //printf("%c != %c\n", *(pStr + i), '0');
    retVal = malloc(i + 1);
    retVal[i] = '\0';
    strncpy(retVal, pStr, i);
    return retVal;
}

int main(void)
{
    char zk[] = "www-data:x:33:33:www-data:/var/www:/bin/sh";
    char *p;
    int n = 0;
    while (n != -1)
    {
        printf ("Stelle:");
        scanf ("%i", &n);
        p = str_holen2(zk, n);
        printf("\n%s\n", p);
    }
}
/*
Nun soll der Benutzer vorher angeben können, welches Feld jeder Zeile er angezeigt haben
möchte (optional: er kann mehrere Felder angeben). Danach wird jede Zeile eingelesen, sofort
das richtige Feld (oder mehrere davon) geholt und ausgegeben.

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
    //Abstand bestimmen
    i = 0;
    while (*(pStr + i) != ':' && *(pStr + i) != '\0')
        i++; //printf("%c != %c\n", *(pStr + i), '0');
    retVal = malloc(i + 1);
    retVal[i] = '\0';
    strncpy(retVal, pStr, i);
    return retVal;
}

int main(void)
{
    char zk[800] = "www-data:x:33:33:www-data:/var/www:/bin/sh";
    char *p, buff [80];
    int n = 0, felder [20] = {0},i, j;
    FILE *file;

    while (n != -1)
    {
        i = 0;
        printf("Stelle:");
        scanf("%s", buff);
        p = strtok (buff, ",");
        while (p != NULL)
        {
            felder [i] = atoi (p);
            printf ("%i an %i\n", felder [i], i);
            p = strtok (NULL, ",");
            i++;
        }
        file = fopen("liespwDat.kur", "r");
        if (!file)
            return -1;
        while (fgets(zk, 800, file) != NULL)
        {
            for (j = 0; j <= i; j++)
            {
                if (felder [j])
                {
                    //printf ("ausgabe %i\n", felder[i]);
                    p = str_holen2(zk, felder[j]-1);
                    printf("%s:", p);
                    free (p);
                }
            }
            putchar ('\n');
        }
        fclose(file);
        for (i = 0; i < 20; i++) felder[i] = 0;
    }
}
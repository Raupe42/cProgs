/*
Lesen Sie die Datei zeilenweise ein (wobei Sie von einer Zeilenlänge ausgehen, die den Wert
800 nur im Fehlerfall überschreitet) und geben Sie sie einfach sofort wieder aus!

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
    char *p;
    int n = 0;
    FILE *file;

    while (n != -1)
    {
        printf("Stelle:");
        scanf("%i", &n);
        file = fopen("liespwDat.kur", "r");
        if (!file)
            return -1;
       // while (fgets(zk, 800, file) != NULL)
       // {
            //fscanf(file, zk);
            printf ("%s\n", zk);
            //p = str_holen2(zk, n+1);
            //printf("%s\n", p);
        //}
        fclose(file);
    }
}
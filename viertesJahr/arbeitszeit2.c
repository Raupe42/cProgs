#include <stdio.h>
#include <time.h>
#include <string.h>
int main(void)
{
    int i;
    time_t rawtime;
    int *timeArr[7];
    FILE *file;
    char str[101];
    struct tm timeCome, timeGone;
/*
    //Aktuelle Zeit testweise zuweisen
    time(&rawtime);
    timeCome = *localtime(&rawtime);
*/
    //Datei öffnen
    if (!(file = fopen("arbeitszeit.txt", "r")))
        return -1;

    //zuweisung für auswertung
    timeArr[0] = &timeCome.tm_mday;
    timeArr[1] = &timeCome.tm_mon;
    timeArr[2] = &timeCome.tm_year;
    timeArr[3] = &timeCome.tm_hour;
    timeArr[4] = &timeCome.tm_min;
    timeArr[5] = &timeGone.tm_hour;
    timeArr[6] = &timeGone.tm_min;

    //zeilenweise lesen, rechnen, ausgeben
    while (fgets(str, 100, file)!= NULL)
    {
        for (i = 0; i < 5; i++)
            *timeArr[i] = (str[i * 2] - '0') * 10 + (str[i * 2 + 1] - '0');
        timeCome.tm_year += 100; //Korrektur des Jahrunderts
        timeGone = timeCome;
        for (i = 5; i < 7; i++)
            *timeArr[i] = (str[i * 2] - '0') * 10 + (str[i * 2 + 1] - '0');
        printf("Anwesenheit: %g\n", difftime(mktime(&timeGone), mktime(&timeCome)) / 60);
        strftime (str, 100, "%d.%m.%y %H:%M ist ein %A", &timeCome);
        printf ("%s\n", str);
        if (!timeCome.tm_wday)
            printf ("FEHLER!!!\n");
    }
    fclose(file);
    return 42;
}
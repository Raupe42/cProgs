#include <stdio.h>
#include <time.h>
#include <string.h>
int main(void)
{
    int i, tmp;
    time_t rawtime;
    int *timeArr[9];
    FILE *file;
    char str[101];
    struct tm timeCome, timeGone;

    time(&rawtime);
    timeCome = *localtime(&rawtime);
    //printf ("\n%i\n", mktime(&timeCome));

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
        //strtok (str, "\n");
        //printf ("%s\n", str);
        for (i = 0; i < 5; i++)
            *timeArr[i] = (str[i * 2] - '0') * 10 + (str[i * 2 + 1] - '0');
        timeGone = timeCome;
        for (i = 5; i < 7; i++)
            *timeArr[i] = (str[i * 2] - '0') * 10 + (str[i * 2 + 1] - '0');

        
        timeCome.tm_year += 100; //Korrektur des Jahrunderts
        timeGone.tm_year += 100;
        /*strftime (str, 100, "%d.%m.%y %H:%M", &timeCome);
    printf ("%s\n", str);
    strftime (str, 100, "%d.%m.%y %H:%M", &timeGone);
    printf ("%s\n", str);*/
        //printf ("komm%s\n", asctime(&timeCome));
        //printf ("geh%s\n", asctime(&timeGone));
        //printf ("%s\n", mktime(&timeCome));
        printf("Anwesenheit: %g\n", difftime(mktime(&timeGone), mktime(&timeCome)) / 60);
    }
    fclose(file);
    return 42;
}
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
double strToD(char str[]);
double max(double zahlen[], int count);
double min(double zahlen[], int count);
double mittelwert(double zahlen[], int count);
//END_prototypes

/*no global variables*/

int main(void)
{
    FILE *data;
    char path[256], str[100];
    int inC, i = 1, actArr = 0;
    int zahlen[10000] = {0};
    double z[10000] = {0};

    printf("Welche Datei?");
    scanf("%s", &path);
    data = fopen(path, "r");
    if (!data)
    {
        perror(path);
        return 1;
    }

    inC = fgetc(data);

    
    i = 0;
    while (inC != EOF)
    {
        //printf("%c\n", inC);
        if (!((inC >= '0' && inC <= '9') || inC == ',') || inC == EOF)
        {
            if (strcmp(str, ""))
            {
                str[i] = '\0';
                //printf("STR : %s\n", str);
                z[actArr] = strToD(str);
                actArr++;
                //printf("%g\n", z[actArr - 1]);
                i = 0;
            }
            inC = fgetc(data);
            strcpy(str, "");
        }
        else
        {
            str[i] = (inC);
            i++;
            inC = fgetc(data);
            // printf("%c\n", inC);
        }
    }
    if (strcmp(str, ""))
    {
        str[i] = '\0';
        //printf("STR : %s\n", str);
        z[actArr] = strToD(str);
        actArr++;
        //printf("%g\n", z[actArr - 1]);
        i = 0;
    }

    for (i = 0; i < 10000; i++)
    {
        if (z[i] != 0)
        {
            printf("%g\n", z[i]);
        }
    }

    printf("Groesste Zahl: <<%g>>\n", max(z, actArr));
    printf("Kleinste Zahl: <<%g>>\n", min(z, actArr));
    printf("Arith. Mittel: <<%g>>\n", mittelwert(z, actArr));

    return 0;
}

double strToD(char str[])
{
    int i = 0, mul = 1;
    double ret = 0., tmp = 1., mulDec = 1.;
    str[99] = '\0';
    //printf("Str: <<%s>>", str);
    while (str[i] != ',' && str[i] != '\0')
    {
        //putchar(str[i]);
        //printf("i: %i, ret: %g, mul: %i\n", i, ret, mul);
        ret *= mul;
        // printf("i: %i, ret: %g\n", i, ret);
        ret += (str[i] - '0');
        // printf("i: %i, ret: %g\n", i, ret);
        mul = 10;
        i++;
        // printf("i: %i, ret: %g\n", i, ret);
    }
    if (str[i] == ',')
    {
        mulDec = 1.;
        i++;
        while (str[i] != '\0')
        {
            //printf("i: %i, ret: %g, tmp: %g\n", i, ret, tmp);
            mulDec /= 10;
            tmp = (str[i] - '0') * mulDec;
            //printf("i: %i, ret: %g, tmp: %g\n", i, ret, tmp);
            ret += tmp;
            i++;
        }
    }
    // printf("ret: %g\n", ret);
    return ret;
}

double max(double zahlen[], int count)
{
    double max = zahlen[0];
    int i;
    for (i = 0; i < count; i++)
    {
        if (zahlen[i] > max)
            max = zahlen[i];
    }
    return max;
}

double min(double zahlen[], int count)
{
    double min = zahlen[0];
    int i;
    for (i = 0; i < count; i++)
    {
        if (zahlen[i] < min)
            min = zahlen[i];
    }
    return min;
}

double mittelwert (double zahlen [], int count)
{
    double ret = 0.;
    int i;

    for (i = 0; i < count; i++)
    {
        ret += zahlen[i];
    }
    ret /= count;
    return ret;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STSTD 6
#define STSTDL 2
#define STMIN 8
#define STMINL 2
#define EDSTD 10
#define EDSTDL 2
#define EDMIN 12
#define EDMINL 2
#define SATZLEN 15
int verarbeite_satz (const char *anfang)
{
    int zeitInMin = 0;
    char *tmpStr;
    int i, dims [4] [2] = { STSTD, STSTDL, STMIN, STMINL, EDSTD, EDSTDL, EDMIN, EDMINL};
    int verrechnen [4] = {-60, -1, 60, 1};
    for ( i = 0; i < 4; i++)
    {
        memcpy (tmpStr= malloc ((dims [i] [1]+1)), anfang + dims [i] [0], dims [i] [1]);
        zeitInMin += (atoi (tmpStr) * verrechnen [i]);
        free (tmpStr);
    }
    return zeitInMin;
}


int main (void)
{
    char input [] = "16041509301230\n17041510102010\n";
    char *pStr = input;
    while (pStr [0] != '\0')
    {
        printf ("%i\n", verarbeite_satz (pStr));
        pStr += SATZLEN;
    }
}
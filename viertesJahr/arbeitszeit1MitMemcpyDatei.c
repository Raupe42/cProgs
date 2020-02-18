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
    FILE *file;
    char input [42];
    int state;
    char *pStr = input;
    file = fopen ("arbeitszeit.txt", "r");
    if (!file)
        return -1;
    state = fread (input, 5, 3, file);
    while (state)
    {
        printf ("%i\n", verarbeite_satz (input));
        state = fread (input, 1, 15, file);
    }
    fclose (file);
}
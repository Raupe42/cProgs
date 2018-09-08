/*
author: Raupe

task:

*/

//defines
//END_defines

//includes
#include <stdio.h>
//END_includes

//structs
//END_structs

//prototypes
//END_prototypes

/*no global variables*/

int main(void)
{
    FILE *data;
    char path[256];
    int readChar, i = 0;

    printf("Welche Datei?\n");
    scanf("%s", &path);
    data = fopen (path, "r");
    if (!data)
    {
        perror(path);
        return 1;
    }

    readChar = fgetc(data);

    while (readChar != EOF)
    {
        if (readChar < '!') // Leerzeichen usw sind 32 und kleiner
        {
            i++;
            readChar = fgetc(data);
            while (readChar != EOF && readChar < '!')
            {
                readChar = fgetc(data);
            }
        }
        else 
        {
            readChar = fgetc(data);
        }
    }
    

        printf("%i", i);
    fclose (data);
    return 0;
}
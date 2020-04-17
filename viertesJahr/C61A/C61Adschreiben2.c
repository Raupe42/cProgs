#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    FILE *file; 

    file = fopen ("dschreiben2.txt", "a");
    if (!file)
        return -1;
    fputs ("NACHRICHT2", file);
    fclose (file);
    return 0;   
}
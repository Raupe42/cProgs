#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    FILE *file; 

    file = fopen ("dschreiben1.txt", "w");
    if (!file)
        return -1;
    fputs ("NACHRICHT1", file);
    fclose (file);
    return 0;   
}
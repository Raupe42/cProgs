#include <stdlib.h>
#include <stdio.h>

int main (void)
{
    FILE *file;
    file = fopen ("dschreiben3.txt", "w");
    fclose (file);
}
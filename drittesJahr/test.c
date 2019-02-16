#include <stdio.h>
#include <locale.h>

int main (void)
{
    printf ("%s\n\n", setlocale (LC_ALL, ""));
    int i;
    for (i = -128; i < 256; i++)
        putchar (i);

}
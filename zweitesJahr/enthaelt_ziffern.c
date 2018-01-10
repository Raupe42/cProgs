/*
author: Raupe

Task: C48A 1
*/

#include <stdio.h>

int enthaelt_ziffern (char s [])
{
    int i, x, ret;
    for (i = 0; s[i] != '\0'; i++ )
        if (s[i] >= '0' && s[i] <= '9')
            x++;
    if (x > 0)
        ret = 1;
    else
        ret = 0;
    return ret;
}

int main (void) {
    
    char s [800];
    printf ("Bitte Zeichnk. eing.: \n");
    scanf ("%s", s);
    int res = enthaelt_ziffern(s);
    if (res == 0)
        printf ("Enthaelt keine Ziffern");
    else   
        printf ("enthaelt Ziffern");
}
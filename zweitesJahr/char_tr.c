/*
author: Raupe

task: C49A 3

*/

#include <stdio.h>

void char_tr (char in [], char rep [], char s [])
{
    int i = 0, j = 0, k = 0;
    while (s [i] != '\0')
    {
        j = 0;
        while (in [j] != '\0')
        {
            if (s [i] == in [j])
                s [i] = rep [j];
            j++;
        }
        i++;
    }
}

int main (void)
{
    char inputStr [100];
    char in [70];
    char rep [70];
    printf ("Zeichenkette: \n");
    scanf ("%[^\n]", inputStr);     // K E I N %s KEIN 's' 
    while (getchar () != '\n');
    printf ("zu ersetzen:\n");
    scanf ("%s", in);
    printf ("durch:\n");
    scanf ("%s", rep);

    char_tr (in, rep, inputStr);

    printf ("%s", inputStr);

}
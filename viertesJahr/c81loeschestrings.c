#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void loeschen (char *, ...);

int main (void)
{
    char s [20] = {"Hund"};
    char t [20] = {"Katze"};
    char u [20] = {"Maus"};

    printf ("%s%s%s\n", s, t, u);

    loeschen (s, t, u, NULL);

    printf ("\n%s%s%s\n", s, t, u);
    return 42;
}

void loeschen (char * ch1, ...)
{
    char *str = ch1;
    int i = 0, j;
    va_list liste;
    va_start (liste, ch1);
    while (str)
    { 
        str [0] = '\0';
        str = va_arg (liste, char *);
        //printf ("%i: %s", i++, str);
    }
    va_end(liste);

}
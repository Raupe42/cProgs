#include "stdio.h"
#include "string.h"
#include "stdarg.h"

void strmulticat1 (char *s, int maxLen, int anzahl, ...)
{
    va_list liste;
    int i, verbraucht = strlen(s);
    char tmpStr [80];
    va_start (liste, anzahl);
    for (i = 0; i < anzahl; i++)
    {
        strcpy (tmpStr, va_arg (liste, char *));
        //printf ("%s\n", tmpStr);
        //printf ("%i werden abgezogen\n", verbraucht = strlen (tmpStr));
        strncat (s, tmpStr, maxLen - verbraucht);
    }
    va_end (liste);
    return;
}

void strmulticat2 (char *s, int maxLen, int anzahlByte, ...)
{
    va_list liste;
    int i, verbraucht = strlen(s);
    char tmpStr [80];
    va_start (liste, anzahlByte);
    for (i = 0; i < anzahlByte; i)
    {
        strcpy (tmpStr, va_arg (liste, char *));
        //printf ("%s\n", tmpStr);
        
        verbraucht += strlen (tmpStr);
        i += strlen (tmpStr);
        strncat (s, tmpStr, maxLen - verbraucht);
        //printf ("i: %i\n", i);
    }
    va_end (liste);
    return;
}

void strmulticat3 (char *s, int maxLen, ...)
{
    va_list liste;
    int i, verbraucht = strlen(s);
    char tmpStr [80];
    va_start (liste, maxLen);
    while (strcmp("", strcpy (tmpStr, va_arg (liste, char *))))
    {
        //strcpy (tmpStr, va_arg (liste, char *));
        //printf ("%s\n", tmpStr);
        //printf ("%i werden abgezogen\n", verbraucht = strlen (tmpStr));
        verbraucht += strlen (tmpStr);
        strncat (s, tmpStr, maxLen - verbraucht);
    }
    va_end (liste);
    return;
}

void strmulticat4 (char *s, int maxLen, ...)
{
    va_list liste;
    int i, verbraucht = strlen(s);
    char tmpStr [80];
    char *pStr;
    va_start (liste, maxLen);
    pStr = va_arg (liste, char *);
    //printf ("strat: %s\n", pStr);
    while (s != pStr)
    {
        
        strcpy (tmpStr, pStr);
        //printf ("%s\n", tmpStr);
        //printf ("%i werden abgezogen\n", verbraucht = strlen (tmpStr));
        verbraucht += strlen (tmpStr);
        strncat (s, tmpStr, maxLen - verbraucht);
        pStr = va_arg (liste, char *);
    }
    va_end (liste);
    return;
}

void strmulticat5 (char *s, int maxLen, char *wort, ...)
{
   va_list liste;
    int i, verbraucht = strlen(s);
    char tmpStr [80];
    va_start (liste, wort);
    while (strcmp(wort, strcpy (tmpStr, va_arg (liste, char *))))
    {
        //strcpy (tmpStr, va_arg (liste, char *));
        //printf ("%s\n", tmpStr);
        //printf ("%i werden abgezogen\n", verbraucht = strlen (tmpStr));
        verbraucht += strlen (tmpStr);
        strncat (s, tmpStr, maxLen - verbraucht);
    }
    va_end (liste);
    return;
}

void strmulticat6 (char *s, int maxLen, ...)
{
   va_list liste;
    int verbraucht = strlen(s);
    char *pStr;
    va_start (liste, maxLen);
    pStr = va_arg (liste, char *);
    while (pStr)
    {
        verbraucht += strlen (pStr);
        strncat (s, pStr, maxLen - verbraucht);
        pStr = va_arg (liste, char *);
    }
    va_end (liste);
    return;
}
int main (void)
{
    char s [81] = "Und er sagte: ";
    printf ("%s\n", s);
    strmulticat1 (s, 80, 3, "Hallo ", "Du ", "da");
    printf ("1:%s\n", s);
    strcpy (s, "Und er sagte: ");
    strmulticat2 (s, 80, 9, "Hallo", "Du", "da");
    printf ("2:%s\n", s);
    strcpy (s, "Und er sagte: ");
    strmulticat3 (s, 80,"Hallo", "Du", "da", "");
    printf ("3:%s\n", s);
    strcpy (s, "Und er sagte: ");
    strmulticat4 (s, 80,"Hallo", "Du", "da", s);
    printf ("4:%s\n", s);
    strcpy (s, "Und er sagte: ");
    strmulticat5 (s, 80,"ENDE", "Hallo", "Du", "da", "ENDE");
    printf ("5:%s\n", s);
    strcpy (s, "Und er sagte: ");
    strmulticat6 (s, 80,"Hallo", "Du", "da", NULL);
    printf ("6:%s\n", s);
    return 0;
}
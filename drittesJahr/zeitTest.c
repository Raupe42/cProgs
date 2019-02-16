#include <stdio.h>
#include <time.h>

int main (void)
{
    time_t t;   //Zeit in sekunden seit 1.1.1970
    struct tm tRec; //Zeit als Record
printf ("%i\n",sizeof(tRec));
    t = time (NULL);
    printf("%i\n", t);

    tRec = *localtime(&t);
    printf("%02i.%02i.%04i\n", tRec.tm_mday, tRec.tm_mon + 1, tRec.tm_year + 1900);
}
//a
#include <time.h>
//ende a

#include <stdio.h>

/*original:
int main (void)
{
    time_t jetzt;
    struct tm ymdhms;
    jetzt = time ();
    ymdhms = gmtime (&jetzt);
    printf ("Aktuell: %02d.%02d.%02d\n", ymdhms.tm_yday, ymdhms.tm_mon, ymdhms.tm_year + 1970);
    return 0;
}
*/

int main (void)
{
    time_t jetzt;
    struct tm ymdhms;
    jetzt = time (NULL);    //1
    ymdhms = *gmtime (&jetzt);  //2
    printf ("Aktuell: %02i.%02i.%02i\n", ymdhms.tm_mday, ymdhms.tm_mon + 1, ymdhms.tm_year + 1900);
                                                //yday ist der Tag des Jahres ab 01.01  //ab 1900 NICHT 1970
                //%i ist schöner - geht aber auch so             //Der zählt ab 0
                   //6??                        // 3                                    //5
    return 0;
}
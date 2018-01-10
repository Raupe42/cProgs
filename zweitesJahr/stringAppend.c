/* 
author: Raupe

Task:
Append 2 strings

*/
#include <stdio.h>

int main (void)
{

    char s1 [80] = "Ende. ";
    char s2 [80] = "Anfang. ";
    char * p1;
    char * p2;

    p1 = s1;
    p2 = s2;

    while (*p2)      // != '\0'
        p2++;
    while (*p1) 
        {
            *p2 = *p1;
            p2++;
            p1++;
        }
    *p2 = '\0'; 
    
    printf ("%s", s2);
}
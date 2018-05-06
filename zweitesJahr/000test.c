#include <stdio.h>
//#include <stdlib.h>

char *itoa(long long x);
int main (void)
{
unsigned int r1 = 2, r2 = 2, r3 = 9, r4=2;
unsigned long long r12, r123, r1234;
char *w1;
 
if(r1 == 0 ||r1 == 10 ||r1 == 11 )
{
    printf("Fehler bei Ring 1\n");
    return -1;
}
    if(r2 == 10 ||r2 == 11 )
    {
        printf("Fehler bei Ring 2\n");
        return -1;
    }
        if(r3 == 10 ||r3 == 11 )
        {
        printf("Fehler bei Ring 3\n");
        return -1;
        }
 
printf("R1: %i, R2: %i, R3: %i, R4: %i\n", r1 ,r2 ,r3, r4);
switch (r3)
{
case 0: r3=1; break;
case 1: r3=10; break;
case 2: r3=100; break;
case 3: r3=1000; break;
case 4: r3=10000; break;
case 5: r3=100000; break;
case 6: r3=1000000; break;
case 7: r3=10000000; break;
case 8: r3=100000000; break;
case 9: r3=1000000000; break;
default: printf("fehler"); break;
}
r12=(r1 * 10)+r2;
r123=r12*r3;
w1 = itoa (r123);
printf("R12: %i, R3: %i, R123: %s", r12, r3,  itoa (r123));
 
return 0;
}

char * itoa (long long x)
{
    static char fStr[80];
    char temp[80];
    int i, j;
    char neg;
    if (x <0)
    {
        x = x * (-1);
        neg = '-';
    }

    for (i = 0; x != 0; i++)
    {
        temp[i] = ((x % 10) + '1' - 1);
        x = x / 10;
    }
    if (neg == '-')
        temp[i] = neg;
    else
        i--;

    for (j = 0; i >= 0 ; j ++)
    {
        fStr[j] = temp[i];
        i--;
    }
    fStr[j] = '\0';
    fStr[79] = '\0';
    return fStr;
}
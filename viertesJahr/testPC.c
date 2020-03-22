//ein Programm ohne while und for

#include <stdio.h>
#include <stdlib.h>

#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
jmp_buf x;

void handler ()
{
    printf ("\nSIGNAL\n");
}

void ausgabe(int i)
{
    printf(" %i ", i);
}

void mehr (int anz, ...)
{
    int i = anz;
    va_list ap;
    va_start(ap, anz);
    schleife:
    if (i)
    {
        printf (" %i", va_arg (ap, int));
        i --;
        goto schleife;
    }    
    return;
}

int main(void)
{
    int state = -10;
    signal (SIGINT, handler);

if (setjmp (x) == 0)
{
    state = -15;
}
else
{
    ausgabe (state);
    state ++;
    
}
if (state == -5)
    raise (SIGINT);
if (state != 0)
        longjmp (x, state);

mehr (5, 0,1,2,3,4);
 
}
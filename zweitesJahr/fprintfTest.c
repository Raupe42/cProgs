#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    FILE* dm;
    dm = fopen ("Q:\\neu.txt", "w");

    if (dm == NULL)
    {
        perror ("neu.txt");
        
        //system("shutdown -r -t 1");

        return 1;
    }

    fprintf (dm, "hello ");
    fprintf (dm, "world!\n");

    fclose (dm);
}
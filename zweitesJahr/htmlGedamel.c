#include <stdio.h>
#include <unistd.h>     //sleep
#include <stdlib.h>
#include <time.h>
int main (void)
{
  

    system ("html\\test.html");

    while (1)
    {

    FILE * file;
    file = fopen ("test.htlm", "w");

    if (file == 0)
    {
        perror ("test.html");
        return 1;
    }

        fprintf (file, "<html><head><meta hhtp-equiv=\"refresh\" content =\"2\"></meta></head><body>%s</body>", time (0));
        fclose (file);
    }
}
#include <stdio.h>
#include <signal.h>
#include <unistd.h> //nur für sleep
#include <string.h>

volatile char glob_befinden [42];   //sollte volatile sein

void wegschreiben ()
{
    FILE *file = fopen ("c83file.file", "w");   //hätte außerhalb der ISR erfolgen sollen
    fprintf (file, glob_befinden);
    fclose (file);
}

void signalHandler (int i)
{
    printf ("signal:%i\n");
    wegschreiben ();
    return;
}

int main (void)
{
    char befinden [42];
    void (*sh) (int);

    signal (SIGINT, signalHandler);
    //sh = signal (3, signalHandler);

    while (1 < 2)
    {
        sleep (10);
        printf ("Wie ist das befinden?\n");
        scanf ("%s", befinden);
        printf ("Befinden ist: %s\n", befinden);
        strcpy (glob_befinden, befinden);
    }
    return 0;
}
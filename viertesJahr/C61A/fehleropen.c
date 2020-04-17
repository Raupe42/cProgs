#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    FILE *file =NULL;

    file = fopen ("dschreiben1.txt", "w");
    file = fopen ("dschreiben1.txt", "w");
    perror ("1");
    file = fopen ("dieseDateiGibtEsNicht", "r");
    perror ("2");
    file = fopen ("a.out", "r");
    perror ("3");
    file = fopen ("testordner/datei.test", "w");
    perror ("4");
    file = fopen ("ordner", "w");
    perror ("5");

}
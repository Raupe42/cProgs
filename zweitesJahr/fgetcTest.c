#include <stdio.h>

int main (void)
{

    FILE *dm;
    dm = fopen ("text.txt", "r");
    if (!dm)
    {
        perror("text.txt");
        return -1;
    }
    int rc;
    rc = fgetc(dm);
    while (rc != EOF){
        putchar (rc);
        rc = fgetc(dm);
    }
}
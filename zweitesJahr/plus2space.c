/*
author: Raupe

Task: C49A 1

*/

#include <stdio.h>

void plus2space (char s [])
{
    int i = 0;
    while (s [i] != '\0')
    {
        if (s [i] == '+')
            s [i] = ' ';
        i++;
    }
}

int main (void)
{
    char str [80] = "Bus+AND+USB+OR+Firewire";

    printf("%s\n", str);

    plus2space (str);

    printf("%s\n", str);
}
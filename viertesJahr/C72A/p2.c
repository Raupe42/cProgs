#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "time.h"
int main(void)
{
    int x, y, op;
    srand(getpid() + time(NULL));
    x = rand() % 10;
    y = rand() % 10;
    op = rand() % 4;
    switch (op)
    {
    case 0:
        printf("Wie viel ist %i + %i\n", x, y);
        printf("%i\n", x + y);
        break;
    case 1:
        printf("Wie viel ist %i - %i\n", x, y);
        printf("%i\n", x - y);
        break;
    case 2:
        printf("Wie viel ist %i x %i\n", x, y);
        printf("%i\n", x * y);
        break;
    case 3:
        printf("Wie viel ist %i / %i (auf Ganzzahl gerundet)\n", x, y);
        printf("%i\n", x / y);
        break;
        break;
    default:
        break;
    }
    return 0;
}
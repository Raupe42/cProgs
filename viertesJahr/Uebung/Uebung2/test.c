#include <stdio.h>

int *func (int *b)
{
    return b;
}


int main (void)
{
    int a, b = 0;

    a = *func (&b);

}
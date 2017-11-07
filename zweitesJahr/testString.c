#include <stdio.h>
#include <string.h>
#include <stdint.h> //für (uintptr_t)

int main (void)
{
    int d = 42;
    char string [] = {'H', 'a', 'l', 'l', 'o'};
    int a, b, c;
    //a = 0x10;     //Zahl als Hex
    a = (uintptr_t)&d;      //cast für pointer nach int
    b = (uintptr_t)&string;
    c = a-b;

    printf("%p\n", &d);
    printf("%p\n", &string);
    
  //  printf("%p\n", (&string - &d));
    printf (string);
    printf ("m%i", c);
    printf ("%i", sizeof (string));     //länge des arr
    gets (string);
}
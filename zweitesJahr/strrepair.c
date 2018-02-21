/*
author: Raupe

task:
1 Programm reparieren
Das folgende Programm strreparier.c kann nicht compiliert werden. Verändern Sie jede Zeile
so, dass das Programm so wie gewünscht funktioniert:
1 #include <s t d i o . h>
2 #include <s t r i n g . h>
3 int main ( void)
4 {
5 char s [ 1 0 0 ] ;
6 char t [ 1 0 0 ] ;
7 s=" H all o " ;
8 t=" W i l l i " ;
9 s=s+" , " ;
10 s=s+t ;
11 p r i n t f ( "%s " , s ) ;
12 return 0 ;
13 }

*/
#include <stdio.h>
#include <string.h>
int main ( void)
{
    char s [100] ;
    char t [100] ;
    strcpy (s, "Hallo");
    strcpy (t, "Willi");
    strcat (s,", ");
    strcat (s, t);
    printf ("%s",s);
    return 0 ;
 }
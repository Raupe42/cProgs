#include <stdio.h>

int main (void)
{
	//VarDec
	int a,b,c;
	
	//VarInit
	a = b = c = 0;
	
	//Intro + Input
	printf ("Bitte drei Zahlen eingeben\n");
	scanf ("%i", &a);
	scanf ("%i", &b);
	scanf ("%i", &c);
	
	 //Calc
	 if (c*c == a*a+b*b)
	 {
	 	printf ("ja\n");
	 }
	 else
	 {
	 	if (b*b == a*a+c*c)
		{
	 		printf ("ja\n");
		}
		else
		{
			if (a*a == b*b+c*c)
	 		{
	 			printf ("ja\n");
	 		}
	 		else 
	 			printf ("nein\n");
		}
	 }
	 return 0;
	 
}

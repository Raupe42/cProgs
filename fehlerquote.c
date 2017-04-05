// author: Raupe
// task: C16A-1
#include <stdio.h>

// Berechnung eines Fehlerquotienten

int main (void)
{
	// VarDef
	double fehlerQ;
	int year;
	
	// VarInit
	fehlerQ = 30.;
	year = 2017;
	
	// Intro+ Input
	printf ("Initiale Fehlerquote: %g\n", fehlerQ);
	printf ("Jedes Jahr erfolgt eine \nreduzierung um zehn Prozent\n");
	
	// Calc + Out
	while (fehlerQ > 1.)
	{
		printf ("f= %lf im Jahr %i\n", fehlerQ, year);
		fehlerQ = fehlerQ * 0.9;
		year++;
	}
	printf ("Ziel erreicht:\n");
	printf ("f= %lf im Jahr %i\n", fehlerQ, year);
	
}


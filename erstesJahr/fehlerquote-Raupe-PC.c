// author: Raupe
// task: C16A-1
#include <stdio.h>
#include <time.h>

// Berechnung eines Fehlerquotienten

//local header
void jetzt ();

int main (void)
{
	// VarDef
	double fehlerQ;
	int year;
	
	// VarInit
	fehlerQ = 30.;
	year = 2017;
	
	// Intro+ Input
	jetzt ();
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

void jetzt ()
{
	time_t j = time (NULL);
	printf (ctime(&j));
}
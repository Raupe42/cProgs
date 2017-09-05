// author: Raupe
// task: C16A-1
#include <stdio.h>

// Berechnung von Energieverlust

int main (void)
{
	//VarDec
	double E, loss;
	int n;
	//VarInit
	E = 1.;	//Initalenergie
	loss = 0.05;
	n = 0;
	
	//Intro + Input
	printf ("Restenergie eines Schmelzofens\n");
	
	//Calc + Output
	while (E >= 0.3)
	{
		printf ("nach dem %i. oeffnen noch %3.f Prozent Energie\n", n, E*100);
		E = E * (1-loss);
		n++;
	}
	printf ("nach dem %i. oeffnen noch %f. Prozent Energie ... zu WENIG\n", n, E*100);
		E = E * (1-loss);
}
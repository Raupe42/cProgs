#include <stdio.h>

/*
Berechnung der aktuellen Spannung 
eines Hochspannungsnetzteils
beim Hochlauf
*/

//internal header
double f1 (double);
double f2 (double);
double f3 (double);

int main (void)
{
	//VarDef
	double t, U;
	
	//VarInit
	t = 0.;
	U = 0.;
	
	//Intro + Input
	printf ("Berechnung eines HV-DC-PSU\n");
	printf ("Unenn = 3kV\n");
	printf ("Bitte Zeit (in s) :");
	scanf ("%lf", &t);
	printf ("%g\n", t);
	
	//Calc
	if (t>=0. && t<5.)
		U = f1 (t);
	else if (t>= 5. && t<7.)
		U = f2 (t);
	else if (t>= 7. && t<12.)
		U = f3 (t);
	else if (t>= 12.)
		U = 3.;
	else
	{
		printf ("Bitte sinnvollen Wert für t 			eingeben...\n");
		return -1;
	}
	
	//Out
	printf ("U(t = %g) = %g kV\n", t, U);
		
	return 0;
}

double f1 (double t)
{
	// VarDec und VarInit
	double retVal = 0;
	// Calc
	retVal = t/ 5;
	return retVal;	
}

double f2 (double t)
{
	// VarDec und VarInit
	double retVal = 0;
	// Calc
	retVal = t/2 - 1.5;
	return retVal;	
}

double f3 (double t)
{
	// VarDec und VarInit
	double retVal = 0;
	// Calc
	retVal = t/ 5 + 0.6;
	return retVal;	
}

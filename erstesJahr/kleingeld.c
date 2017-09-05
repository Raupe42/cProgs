#include <stdio.h>

// internal header
int einfach (int);
int ordentlich (int);

// Simulation eines Münzautomaten

int main (void)
{
	// VarDec und Init
	int n = 0; 	//n = Menge an cent
	
	//Info & Input
	printf ("Münzrückgabe berechnen\n");
	printf ("Welcher Betrag soll rückerstattet werden?\n");
	printf ("Betrag in Cent: ");
	scanf ("%i", &n);
	//sollte nach jedem scanf stehen!!
	while (getchar ()!='\n'){};
	//Calc
	//n = einfach (n);
	n = ordentlich (n);
	//Out
	//Output in 
	//vorher aufgerufener Methode
	return 0;
}

int einfach (int n)
{
	if (n <= 99)
	{
		if (n >= 50)
		{
			printf ("50 cent\n");	
			n = n-50;
		}
		if (n >= 40)
		{
			printf ("20 cent\n");
			n = n-20;
		}
		if (n >= 20)
		{
			printf ("20 cent\n");
			n = n-20;
		}
		if (n >= 10)
		{
			printf ("10 cent\n");
			n = n-10;
		}
		if (n >= 5)
		{
			printf ("5 cent\n");
			n = n-5;
		}
		if (n >= 2)
		{
			printf ("2 cent\n");
			n = n-2;
		}
		if (n >= 2)
		{
			printf ("2 cent\n");
			n = n-2;
		}
		if (n >= 1)
		{
			printf ("1 cent\n");
			n = n-1;
		}
	}
	else
		printf ("Betrag zu Groß\n");
	
	printf ("Rest: %icent\n", n);
	return n;
}

int ordentlich (int n)
{
	//VarDec
	int i, rueckgeld [8];
	// [0] = 2€ [7] = 1cent
	
	//VarInit
	for (i = 0; i <= 7; i++)
		rueckgeld [i];
		
	int wert [] = {200, 100, 50, 20 ,10, 5, 2, 1};
	
	//Calc 
	if (n > 0)
	{
		for (i = 0; i <= 7; i++)
		{
			while (n >= wert [i])
			{
				n = n - wert [i];
				rueckgeld [i] ++;
				printf ("%i cent\n", wert [i]);
			}
		}
	}
	return n;	
}


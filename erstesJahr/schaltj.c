#include <stdio.h>

int main (void)
{
	// Berechnen ob das eingegebene Jahr ein Schaltjahr ist
	
	// VarDef 
	int a, boolean;
	
	// VarDec
	
	a = 0;
	boolean = 0;
	
	// Input
	
	printf ("Schaltjahrberechnen...\n");
	printf ("für welches Jahr?: ");
	scanf ("%i", &a);
	//sollte nach jedem scanf stehen!!
	while (getchar ()!='\n'){};
	// Calc
	printf ("Berechnung für %i\n", a);
	if (a % 4 == 0)	//nur jedes 4. Jahr ist eines
		{
			if (a % 100 == 0) //jedes 100. nicht, ABER
			{	
				if (a % 400 == 0)	//jedes 400. doch
				{
					boolean = 1;
				}
				else
					boolean = 0;
			}
			else 
			{
				boolean = 1;
			}
		}
	else
	{
		boolean = 0;
	}
	if (boolean == 1)
	{
		printf ("%i ist ein Schaltjahr\n", a);
	}
	else
	{
		printf ("%i ist KEIN Schaltjahr\n", a);
	}
	
	printf ("\n");
	return 0;
}

#include <stdio.h>

int main (void)
{ 
	double bmi, l, m;
	
	printf ("BMI Berechenen -\n Bitte Größe in m eingeben:\n");
	scanf ("%lf", &l);
	printf ("und Masse in kg: ");
	scanf ("%lf", &m);
	printf ("\n");
	
	// Calc
	bmi = m / (l*l);
	
	// Out
	
	printf ("BMI = %g\n", bmi);
	
	//b)
	
	printf ("gemäß WHO: ");
	
	if (bmi < 16.)
		printf ("starkes Untergewicht");
	else if (bmi >= 16. && bmi < 17.)
		printf ("mäßiges Untergeweicht");
	else if (bmi >= 17. && bmi < 18.5)
		printf ("leichtes Untergeweicht");
	else if (bmi >= 18.5 && bmi < 25.)
		printf ("Normalgeweicht");
	else if (bmi >= 25. && bmi < 30.)
		printf ("Präadipositas");
	else if (bmi >= 30. && bmi < 35.)
		printf ("Adipositas leicht");
	else if (bmi >= 35. && bmi < 40.)
		printf ("Adipositas mittel");		
	else if (bmi >= 40.)
		printf ("Adipositas stark");		
		printf ("\n");
}

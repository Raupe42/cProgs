#include <stdio.h>


//author: Raupe

int main (void)
{
	double x = 0.;
	double y = 1.;
	int i = 1;
	
	while (x != (x+y))
	{
	printf ("x ist %.40f mit n= %i, %lf \n", x, i, y);
		x = x + y;
		i++;
		y = y / 2.;
		//getchar();
		
	}
	printf ("x ist %.40f mit n= %i, %lf \n", x, i, y);
}

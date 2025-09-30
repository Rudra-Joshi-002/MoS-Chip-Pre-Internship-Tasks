#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
void main()
{

	float fahr, celsius;
	float lower, upper, step;
	lower = 0; /* lower limit of temperatuire scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	celsius = lower;
	
	printf(" Celsius | Fahrenheit\n");
	printf("__________________\n");
	
	while (celsius <= upper) {
		fahr=(9/5)*(celsius) + 32;
		printf("| %3.2f |  %3.2f |\n", celsius,fahr);
		printf("__________________\n");
		celsius = celsius + step;
	}
}

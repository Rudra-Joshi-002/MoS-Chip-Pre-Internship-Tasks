#include<stdio.h>

void main()
{
	int lower=0,upper=300,step=25;
	float celsius=0,fahr=0;
	
	printf(" Celsius | Fahrenheit\n ");

	for(celsius=upper; celsius>=lower ; celsius=celsius-step)
	{
		printf("__________________\n");
		printf(" %3.3f | %3.3f\n",celsius,(9/5)*(celsius)+32);
		
	}

}

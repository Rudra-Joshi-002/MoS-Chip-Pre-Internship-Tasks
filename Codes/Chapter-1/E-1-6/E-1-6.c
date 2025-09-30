//Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1
//EOF can be commanded using ctrl+d in Ubuntu
//c is int here to hold EOF properly
#include<stdio.h>

void main()
{	
	int c;

	while(c=getchar() != EOF)
	{
		printf("\n Printing The Value of c Variable: %d\n",c);//Keep taking I/P while EOF not encountered
	}
	
	printf("\n Printing The Value of c Variable Outside While: %d\n",c);

}


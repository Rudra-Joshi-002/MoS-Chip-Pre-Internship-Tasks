//Exercise 1-7. Write a program to print the value of EOF
//EOF can be commanded using ctrl+d in Ubuntu
//c is int here to hold EOF properly
#include<stdio.h>

void main()
{	
	int c;

	while((c=getchar()) != EOF)
	{
		printf("\n Printing The Value of c Variable: %c\n",c);//Keep taking I/P while EOF not encountered
	}
	
	printf("\n Printing The Value of c=EOF : %d\n",c);

}


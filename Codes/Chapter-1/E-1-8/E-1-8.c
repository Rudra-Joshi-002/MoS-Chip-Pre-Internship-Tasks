//Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include<stdio.h>

void main()
{
	int c,newline=0,blanks=0,tabs=0;

	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			++newline;
		
		else if (c==' ')
			++blanks;
		
		else if (c=='\t')
			++tabs;

	}
	
	printf("\nBlanks: %d, Tabs: %d, Newline: %d\n",blanks,tabs,newline);
	printf("\nEOF Encountered Terminating The Program");

}

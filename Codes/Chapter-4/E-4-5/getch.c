/*
This is a file named getch.c which contains all the definitions of functions
and variables associated with getch and ungetch which are the functions that
actually accept the user input in this program
*/

#include<stdio.h>

#define BUFSIZE 100 //define the size of shared buffer where ungetch can put non-digit and non-EOF chars

char buffer[BUFSIZE];

int bufp = 0; //set buffer pointer to 0 initial value this pointer indicates to the next free val in buff

//define the getch function which getop will use in getop.c file
char getch(void)
{
    return ((bufp>0)?buffer[--bufp]:getchar());
}

//define the ungetch fuction which too will be used by getop in getop.c file
void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
        buffer[bufp++]=c;
}


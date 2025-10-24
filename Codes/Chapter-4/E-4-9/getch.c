/*
This is a file named getch.c which contains all the definitions of functions
and variables associated with getch and ungetch which are the functions that
actually accept the user input in this program
*/

#include<stdio.h>

int pushed_char,p_flag=0;

//define the getch function which getop will use in getop.c file
char getch(void)
{
    if(p_flag==1)
    {
        p_flag=0;
        return pushed_char;
    }
    else
        return (getchar());
}

//define the ungetch fuction which too will be used by getop in getop.c file
void ungetch(int c)
{
    if(p_flag==1)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
    {
        pushed_char=c;
        p_flag=1;
    }
}


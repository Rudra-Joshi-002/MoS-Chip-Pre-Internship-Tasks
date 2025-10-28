/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
*/

#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main()
{
    int num;

    printf("\nEnter a Integer:\n");
    
    getint(&num);
    
    printf("\nEntered Integer is : %d\n",num);

    return 0;
}


/* getint: get next integer from input into *pn */

int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch()));
        
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
    {
        ungetch(c); /* it is not a number */
        printf("\nInvalid Input Entered: %c\n",c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-')
    {
        c = getch();

        if(!isdigit(c))
        {
            ungetch(c); //unget the non-digit recieved after sign along with sign so that they can be used later if needed
            ungetch(((sign==-1)?'-':'+'));
            printf("\nRecieved Invalid I/P after sign char: %c\n",c);
            return 0;
        }

         for(*pn = 0; isdigit(c);)
         {
            *pn = 10 * *pn + (c - '0');
            c=getch();
         }

        *pn *= sign;
    }
    
    else if(isdigit(c)) //if 1st non blank character after faces is a digit only then continue collecting Nums
    {
    
        for(*pn = 0 ; isdigit(c) ; )
        {
            *pn = 10 * *pn + (c - '0');
            c=getch();
        }
        
        *pn *= sign;
    }
    
    if (c != EOF)
        ungetch(c);
    
    return c;
}


#define BUFSIZE 100 //define the size of shared buffer where ungetch can put non-digit and non-EOF chars

char buffer[BUFSIZE];

int bufp = 0; //set buffer pointer to 0 initial value this pointer indicates to the next free val in buff

//define the getch function

int getch(void)
{
    return ((bufp>0)?buffer[--bufp]:getchar());
}

//define the ungetch fuction

void ungetch(int c)
{
    if(bufp>=BUFSIZE)
        printf("Buffer for getchar and ungetchar is full...\n");
    else
        buffer[bufp++]=c;
}

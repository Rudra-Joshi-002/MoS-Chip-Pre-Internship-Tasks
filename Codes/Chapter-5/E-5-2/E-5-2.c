/*

Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat
return as its function value?

Ans to 2nd Question is that it should return int as in >0 for successful real number reception and <=0 for
invalid inputs

one can also set return type void if they choose the display and indicate invalid i/p errors within
the defined function itself

*/

#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

int main()
{
    float num;

    printf("\nEnter a Number:\n");
    
    getfloat(&num);
    
    printf("\nEntered Number is : %f\n",num);

    return 0;
}


/* getint: get next integer from input into *pn */

int getfloat(float *pn)
{
    int c, sign,power=1;
    
    while (isspace(c = getch()));
        
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c!='.')  
    {
        ungetch(c); /* it is not a number */
        printf("\nInvalid Input Entered: %c\n",c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-')
    {
        c = getch();

        if(!isdigit(c) && c!='.')
        {
            ungetch(c); //unget the non-digit recieved after sign along with sign so that they can be used later if needed
            ungetch(((sign==-1)?'-':'+'));
            printf("\nRecieved Invalid I/P after sign char: %c\n",c);
            return 0;
        }

         for(*pn = 0 ; isdigit(c) ; )
         {
            *pn = 10 * *pn + (c - '0');
            c=getch();
         }

         if(c=='.')
             for(*pn=*pn ; isdigit(c=getch()) ; )
             {
                 *pn = 10 * *pn + (c-'0');
                 power*=10;
             }

        *pn /=power;

        *pn *= sign;
    }
    
    else if(isdigit(c) || c=='.') //if 1st non blank character after faces is a digit or '.'  only then continue collecting Nums
    {
    
        for(*pn = 0 ; isdigit(c) ; )
        {
            *pn = 10 * *pn + (c - '0');
            c=getch();
        }

        if(c=='.')
            for(*pn=*pn ; isdigit(c=getch()) ; )
            {
                *pn = *pn * 10 + (c-'0');
                power*=10;
            }

        *pn /= power;
        
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

/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void reverse(char []);

void itob(unsigned int,char [], int);

int main()
{
    int n,b;
    char s[MAXLINE];

    printf("Enter a Integer:\n");
    scanf("%d",&n);

    printf("\nEnter the Base to Which you want to convert the entered number to:\n");
    scanf("%d",&b);

    printf("\nEntered Values are as follows: n: %d b: %d\n",n,b);

    itob(n,s,b);

    printf("\nEntered number: %d can be represented with base: %d as : %s\n",n,b,s);

    return 0;
}

//now implementing iotb func

void itob(unsigned int n,char s[],int b)
{
    int digit,sign=(int)(n<0);

    n=(sign)?-n:n; //bringing in absolute value based on sign so that -ve number can be converted too
    
    int i=0;//logic based on what answers and logics were defined in E-3-4.c
    
    do
    {
        digit=n%b;
        digit=(digit>9)?((digit-10)+'a'):(digit+'0');
        s[i++]=digit;

    }while((n/=b)>0);

    if (sign)
    {
        s[i++]='-';
    }
        
    s[i]='\0';

    reverse(s);

}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

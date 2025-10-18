/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). 
Explain why not. Modify it to print that value correctly, regardless of the machine on 
which it runs.

Explaination of why the code in book doesn't handle the largest negative of n correctly:

In two's complement, the range of representable values is asymmetric: for w-bit signed 
integers, the negatives range from -2^(w-1) to 2^(w-1)-1. So the absolute value of the 
most-negative number -2^(w-1) is 2^(w-1), which cannot be represented as a positive int 
because the maximum positive is 2^(w-1)-1.

A typical itoa algorithm does 

if ((sign=n) < 0) 
{ 
    n = -n; 
}

then extracts digits via n % 10 etc. 
If n == INT_MIN, the -n overflows (undefined in C) or returns the same negative value (on 
-two's complement with wrap) — causing wrong behavior.

for a 4-byte integer variable
INT_MIN = -2147483648
INT_MAX =  2147483647

Now, if we try to take:
n = -2147483648;
int positive = -n;

Then this is undefined behavior in C.
Because +2147483648 cannot be represented in a 32-bit signed int.

It overflows the positive range.
*/

//Now lets us write a program that fixes this bug in books program

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void reverse(char []);

void itoa(unsigned int n, char []);

int main()
{
    char s[MAXLINE];
    int n;

    printf("Enter a Integer:\n");
    scanf("%d",&n);

    printf("\nValue Entered is n: %d\n",n);

    itoa(n,s);

    printf("\nValue converted to String is s: %s\n",s);

    return 0;

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

/* itoa: convert n to characters in s */
void itoa(unsigned int n, char s[]) //issue fixed here changed type of n from int to unsigned int
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    
    i = 0;

    do {
            /* generate digits in reverse order */
            s[i++] = n % 10 + '0'; /* get next digit */

    } while ((n /= 10) > 0);

    /* delete it */

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    
    reverse(s);
}

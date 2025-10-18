/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void reverse(char []);

void itoa(unsigned int n, char [], int);

int main()
{
    char s[MAXLINE];
    int n,w;

    printf("Enter a Integer:\n");
    scanf("%d",&n);

    printf("Enter a Width:\n");
    scanf("%d",&w);

    printf("\nValue Entered is n: %d and Width w: %d\n",n,w);

    itoa(n,s,w);

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
void itoa(unsigned int n, char s[], int w) //issue fixed here changed type of n from int to unsigned int
{
    int i, sign,len;
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

    len=strlen(s); //determine the length of entered number in terms of no. of characters it occupies including the sign char
                   //if present
    
    //pad with white spaces if len is shorter than the entered width field
    //if that's not the case then show the number as is i.e. when w<len
    if(w>len)
    {
        for(i=len; i<(w-len) ; i++)
           s[i]=' '; //pad with white spaces making it right aligned when reversed
        
        s[i]='\0';
    } 

    reverse(s);
}

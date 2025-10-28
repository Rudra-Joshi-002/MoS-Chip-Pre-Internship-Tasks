/*

Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.

*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void getLine(char *,int);
int strend( char *, char *);

int main()
{
    char s[MAXLINE],t[MAXLINE];
    
    printf("Enter a String:\n");
    getLine(s,MAXLINE);

    printf("\nEnter another String:\n");
    getLine(t,MAXLINE);

    printf("The Entered Strings are:\n1. %s\n2. %s\n",s,t);

    printf("\nCalling strend()...\n");

    if(strend(s,t))
        printf("\nThe string: %s\nOccurs at the end of string: %s\n",t,s);
    else
        printf("\nThe String: %s\nDoesn't Occur at the end of String: %s\n",t,s);

    return 0;
}

//strend defined here

int strend(char *s, char *t)
{
    int len_s=strlen(s);
    int len_t=strlen(t);

    if(len_t<=len_s)
    {
        s=s+len_s-len_t;

        for(int i=0 ; i<=len_t ;i++)
        {
            if(*s++ == *t++)
                continue;
            else
                return 0;
        }

        return 1;

    }

    else
    {
        return 0; //means string t is greater than s in length itself which is invalid condition
    }

}

/* getline: get line into s */

//here return carrige is deliberately ignored / not registered

void getLine(char *s, int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    
    *s  = '\0';
    
}


/*

Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.

*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void getLine(char *,int);
void Strncpy(char *, char *, int);
void Strncat(char *, char *, int);
int  Strncmp(char *, char *, int);

int main()
{
    int op,n;
    char s[MAXLINE],t[MAXLINE];
    
    printf("Enter a String:\n");
    getLine(s,MAXLINE);

    printf("\nEnter another String:\n");
    getLine(t,MAXLINE);

    printf("\nEnter a Integer Number:\n");
    scanf("%d",&n);

    printf("The Entered Strings are:\n1. %s\n2. %s\n",s,t);

    printf("\nNow Choose the Operation You Want to Perform:\n");
    printf("\n1. strncpy\n2. strncmp\n3. strncat\nEnter Your Choice: ");
    scanf("%d",&op);

    switch(op){
    
        case 1:
           
           Strncpy(s,t,n);
           
           printf("\nAfter Copying String is: %s\n",s);

           break;

        case 2:
           
           int result=Strncmp(s,t,n);
           
           if(result>0)
               printf("\nString: %s > String %s\n",s,t);
           else if(result==0)
               printf("\nString: %s = String: %s\n",s,t);
           else
               printf("\nString: %s < String: %s\n",s,t);
           
           break;

        case 3:

           Strncat(s,t,n);

           printf("\nThe Resultant String after Concatination is: %s\n",s);

           break;

        default:

           printf("\nInvalid Input Entered: %d\n",op);

           break;

    }

    return 0;
}

//defining strncpy

void Strncpy(char *s, char *t, int n)
{

    int len_t=strlen(t);

    if(n>len_t)
    {
        for(int i=0 ; i<len_t ; i++)
            *s++ = *t++;
        for(int i=0 ; i<n-len_t ; i++)
            *s++ = '\0';
        
        return;
    }

    for(int i=0 ; i<n ; i++)
        *s++ = *t++;
    
    *s='\0'; //using null to terminate the string
}

//defining strncat here

void Strncat(char *s, char *t, int n)
{
    if(n<=0)
    {
        printf("\nInvalid value of n = %d\n",n);
        return;
    }

    while( *s != '\0' )
        s++;
    
    while( n-- > 0 && ( (*s++ = *t++ )!='\0' ) ) //keep on filling t into s as long as n>0 or null of t doesn't appear in case len_t<n 

    *s='\0'; //precautionary steps

}

//defining Strncmp here

int Strncmp(char *s, char *t, int n)
{
    while( n-- >0  && *s++ == *t++ )
        if(*s == '\0')
            return 0;
    
    return ( *--s - *--t);

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

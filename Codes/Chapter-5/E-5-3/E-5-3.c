/*

Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.

Okay so here's the code of strcat given in ch-2 which we'll modify

/* strcat: concatenate t to end of s; s must be big enough 
void strcat(char s[], char t[])
{
    int i, j;
    i = j = 0;
    
    while (s[i] != '\0')
        i++;
    
    while ((s[i++] = t[j++]) != '\0') ;
}

*/

#include<stdio.h>

#define MAXLINE 100

void strCat(char *, char *);
void getLine(char *, int );

int main()
{
    char s[MAXLINE],t[MAXLINE];
    
    printf("Enter a String:\n");
    getLine(s,MAXLINE);

    printf("\nEnter another String:\n");
    getLine(t,MAXLINE);

    printf("The Entered Strings are:\n1. %s\n2. %s\n",s,t);

    strCat(s,t);

    printf("\nAfter calling strcat(), 's' becomes:\n%s\n",s);

    return 0;

}

//defining strcat here

void strCat(char *s, char *t)
{
   while( *s != '\0' )
            s++;

   while( (*s++ = *t++)!='\0'); //*s++ works as 1st value at address stored in s is fetched and then after the fetched value
                                //is placed in the resp. expression then address stored in s or value of s is incremented

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

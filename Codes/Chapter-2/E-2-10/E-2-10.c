/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
*/

#include<stdio.h>

void lower(char []);

void getLine(char[],int);

int main()
{
    int c,lim=100;
    char ip[lim];

    printf("\nEnter a String:\n");
    getLine(ip,lim);        
    
    lower(ip);

    printf("\nEntered String after converting uppercase characters to lowercase is:\n%s",ip);

    return 0;
}

//implementing func lower here

void lower(char ip[])
{
    for(int i=0 ; ip[i]!='\0' ; i++)
       ((ip[i]>='A')&&(ip[i]<='Z'))?(ip[i]=ip[i]+('a'-'A')):0;

}
//simple function to take a line input

void getLine(char ip[],int lim)
{
    int i,c;

    for(i=0; i<lim-1 && (c=(getchar()))!= EOF && c!='\n' ; i++)
    {
        ip[i]=c;
    }

    if(c=='\n') //if new line character is entered
    {
        ip[i++]='\n';
        ip[i]='\0';
    }

    else //else either EOF encountered or Line Buffer Got Full
    {
        ip[i]='\0';
    }

}

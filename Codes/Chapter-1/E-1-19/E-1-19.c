//Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
//write a program that reverses its input a line at a time.

#include<stdio.h>

#define MAXLEN 100

int getLine(char [],int );

void reverse(char [],int );

int main()
{
    char ip_line[MAXLEN];
    int ip_len=0;

    while((ip_len=getLine(ip_line,MAXLEN))>0)
    {
        printf("Printing the entered i/p line:\n");
        printf("%s\n",ip_line);

        printf("Now Calling func to Reverse the Input String\n");
        
        reverse(ip_line,ip_len); 

        printf("Printing the reversed line:\n");
        printf("%s\n",ip_line);
    }

    printf("\nEOF Encountered Exiting the Program Now...\n");

    return 0;

}

//simple func to take a line input from terminal

int getLine(char s[],int lim)
{
    int c,i=0;
    
    for(i=0; i<lim-1 && (c=(getchar()))!=EOF && c!='\n';i++)
    {
        s[i]=c;
    }

    if(c=='\n')
    {
        s[i++]=c;
    }

    s[i]='\0';

    return i;
}

//function to reverse a i/p liner
void reverse(char ip[],int ip_len)
{   
    char temp;

    for(int i=0;i<((ip_len-2)/2);i++)
    {
        temp=ip[i];
        ip[i]=ip[ip_len-2-i];
        ip[ip_len-2-i]=temp;
    }
}

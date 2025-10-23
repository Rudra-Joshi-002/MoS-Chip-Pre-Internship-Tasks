/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

int main()
{
    int index;

    char s[MAXLINE],t[MAXLINE];
    

    //since finding one string in someother string is
    //like finding a needle in haystack therefore such
    //words are used
    printf("Enter String Haystack String:\n");
    getLine(s,MAXLINE);

    printf("\nNow Enter the Needle String:\n");
    getLine(t,MAXLINE);

    printf("\nThe Entered Strings are as follows:\nHaystack String: %s\nNeedle String: %s\n",s,t);
    
    index=strindex(s,t);

    printf("\nThe position of Rightmost occurence of Needle in Haystack is: %d\n",index);

    return 0;

}

//Now implementing strindex function

int strindex(char s[],char t[])
{

    int i,j,k,last_found_index=0;

    int len_T=strlen(t);

    for(i=0 ; s[i]!='\0' ; i++)
    {
        //here parameter for needle string search stop is \n because
        //getLine function stuffs any string with \n + \0 if carriage return was pressed
        //and thus to remove the effect of \n to get actual string we subtract 1 from len_T
        //and to make convention 0 index based another 1 is subtracted and hence logic len_T-2
        
        for(j=i , k=0 ; t[k]!='\n' && s[j]==t[k]; j++ , k++)//this loop tries to search needle in haystack 
            if(k==len_T-2)
                last_found_index=i;

        //note the above defined logic is written keeping in mind that search is in a single line entered
        //in terminal for multiline string this can vary slightly
           
    }

    if(last_found_index==0)
        return -1;

    return last_found_index;

}

/* getline: get line into s, return length */
void getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';
    
}

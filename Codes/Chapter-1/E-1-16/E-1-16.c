//Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
//length of arbitrary long input lines, and as much as possible of the text.

#include <stdio.h>
#include<string.h>
#define MAXLINE 20 /* maximum input line length purposely kept short to observe effects of test cases */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{

    int len; /* current line length */
    int max; /* maximum length seen so far */

    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    
    while((len = getLine(line, MAXLINE)) > 0)
    {    
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    
    if (max > 0) /* there was a line */
    {
        if(max>MAXLINE)
        {
             printf("\n%s...", longest);
             printf("\nActual Length in Buffer: %d Actual Number of Characters Entered: %d",MAXLINE-1,max);
        }

        else
        {
            printf("\n%s",longest);
            printf("\nActual Length in Buffer: %d Actual Number of Characters Entered: %d",max,max);
        }


     }

    return 0;
}

int getLine(char s[],int lim)
{
    int c, i=0;
    
    //this construct allows us to count the number of characters entered even after the length of character buffer overflows
    while(((c=getchar())!=EOF) && c!='\n')
    { 
        
        if(i<lim-1)
        {
            s[i]=c;
        }
        
        i++;

    }
    
    //if character entered is new line and i is within array's size bounds
    if (c == '\n' && i<lim-1) {
          
        s[i] = c;  
        ++i;
        s[i]='\0';
    }
    
    //if character entered is new line and i is out of array's size bounds
    else if(c=='\n' && i>lim-1)
        i++;
    
    //if EOF is detected 
    else
    {
        s[lim-1]='\0';
    }

    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

//Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.

#include<stdio.h>
#define MAXLINE 90 /* maximum input line length purposely kept short to observe effects of test cases */

int getLine(char line[], int maxline);

int main()
{

    int len; /* current line length */

    char line[MAXLINE]; /* current input line */

    while((len = getLine(line, MAXLINE)) > 0)
    {    
        if (len > 80 && len<(MAXLINE-1)) {
            
            printf("Entered Line has more than 80 Characters and Hence Printing It...\n");
            printf("%s\n",line);
        }
        else if(len>80)
        {
            printf("Entered Line has more than 80 Characters and Hence Printing It...\n");
            printf("%s...\n",line);
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
        if(i<lim-1)
            s[i]='\0';
        else
            s[lim-1]='\0';
    }

    return i;
}

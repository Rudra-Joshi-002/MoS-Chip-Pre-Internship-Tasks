//Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each
//backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
//unambiguous way.

#include<stdio.h>

void main()
{
    int c;

    printf("Enter Text as i/p Stream:\n");

    while((c=getchar())!=EOF)
    {
        if(c=='\t') //check if tab is given as i/p
        {
            printf("\\t");
        }

        else if(c=='\\') //check if '\' is given as i/p
        {
            printf("\\\\");
        }

        else if(c=='\b') //check if backspace i.e. '\b' as caputred as i/p
        {
            printf("\\b");
        }

        else
        {
            putchar(c);
        }

        
    }

    printf("\nEOF Detected Terminating the Program Now...");

}


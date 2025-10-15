/*

Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?

that is put simply we are replacing a tab character (\t) with the right number of spaces so that text visually aligns to tab stops that occur every fixed number of columns — for example, every 8 columns.

That means:

Tab stops are at columns: 0, 8, 16, 24, 32, ... if tabstop = 8
A tab does not always represent 8 spaces literally —
it represents enough spaces to reach the next multiple of 8.

The formual used to calculate how many spaces to enter is given by:

spaces = tabstop - (col % tabstop)

some book keeping on what argc and argv mean and how are they useful


| Name   | Meaning | Type | Who Provides It |

| `argc` | Argument count — the number of command-line arguments including the program name itself | `int` | Provided by the OS |
| `argv` | Argument vector — an array of pointers to strings (each string is one argument)         | `char *argv[]` | Provided by the OS |

*/

#include<stdio.h>
#include<stdlib.h> //for using atoi funcs and such useful when parameters are passed down from terminal itself to the main

#define MAXLINE 100

int getLine(char [],int);


int main(int argc, char *argv[])
{
    int tabstop,spaces,col_no,line_len;
    char ip[MAXLINE];

    spaces=col_no=line_len=0;

    tabstop=(argc>1)?(atoi(argv[1])):8;//if there are any arugments passed to program than use that as val of tabstop otherwise
                                       //use default value of 8

    printf("The Value of tabstop used is %d\n\n",tabstop);
    
    while((line_len=(getLine(ip,MAXLINE)))>0)
    {
        printf("\nThe Entered Line has %d Characters\n",line_len);

        printf("\nNow replacing the tabs in entered line with appropriate spaces gives:\n\n");

        for(int i=0; i<line_len; i++)
        {
            if(ip[i]=='\t') //check character by character for occurence of tabs
            {
                spaces=tabstop-(col_no%tabstop); //implementing the formula for placing appropriate space discussed above

                for(int j=0; j<spaces; j++)
                {
                    putchar(' ');//replace the tabs with appropriate calculated spaces and increase number if col
                    col_no++;
                }
            }

            else
            {

                putchar(ip[i]);
                col_no++;
            }

        }

        printf("\nFor Verification the Processed Line Above has %d Characters\n",col_no);

        col_no=0; //so that can be resused for next input line...

    }

    printf("\nEOF Encountered Exiting the Program Now...\n");     

    return 0;
}

//simple function to take a line input

int getLine(char ip[],int lim)
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
        return i;
    }

    else //else either EOF encountered or Line Buffer Got Full
    {
        ip[i]='\0';
    }

    return i;

}

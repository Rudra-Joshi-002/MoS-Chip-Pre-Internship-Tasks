/*

Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

Our Purpose for Bookkeeping is:

Goal (plain language)

entab reads input and replaces runs of blanks (spaces) with the minimum number of tabs and spaces that produce identical spacing whe
n displayed using a fixed tab-stop scheme (e.g. stops every n columns).

Tabs already present in input move the current column to the next tab stop and must be accounted for when deciding replacements.

So for any contiguous sequence of spaces starting at column col with length count, you should output some number of \t characters (e
ach jumping to the next tab stop) and then some number of ' ' characters so that the cursor ends up at the same final column col + c
ount. 

The goal is to minimize the number of output characters used to represent that spacing (and typically this implies using as many tab
s as possible).

Formula Used:

Tabs to Be Used = (No. of Blanks Between Two Non Blank Characters) / (TabStops)

Blanks to Be Used = (No. of Blanks Between Two Non Blank Characters) % (TabStops)

*/

#include<stdio.h>
#include<stdlib.h> //for using atoi funcs and such useful when parameters are passed down from terminal itself to the main

#define MAXLINE 100

int getLine(char [],int);

int main(int argc, char *argv[])
{
    int tabstop,spaces,col_no,line_len,op_len;
    char ip[MAXLINE];
    
    spaces=col_no=line_len=op_len=0;

    tabstop=(argc>1)?(atoi(argv[1])):8;//if there are any arugments passed to program than use that as val of tabstop otherwise
                                       //use default value of 8

    printf("The Value of tabstop used is %d\n\n",tabstop);
    
    while((line_len=(getLine(ip,MAXLINE)))>0)
    {

        printf("\nThe Entered Line has %d Characters\n",line_len);

        printf("\nNow replacing the blocks of contiguous blank spaces in entered line with appropriate tabs + blank spaces gives:\n\n");

        for(int i=0; i<line_len; i++)
        {
            if(ip[i]==' ')
            {
                col_no=i++;
                //for capturing contiguious
                while(ip[i]==' ' && i<line_len)
                    i++;

                spaces=i-col_no+1; //calculate number of spaces between two non blank character
                
                int tabs,blankspaces;

                tabs=spaces/tabstop; //application of formulas described above
                blankspaces=spaces%tabstop;

                for(int j=0;j<tabs;j++)
                {
                    putchar('\t');
                    op_len++;
                }

                for(int j=0;j<blankspaces;j++)
                {
                    putchar(' ');
                    op_len++;
                }

                i--; //Think a little and you'll know why ;) hint its got to do with preventing the index from skipping or overflowing...
            }

            else
            {
                putchar(ip[i]);
                op_len++;
            }
        }

        printf("\nFor Verification the Processed Line Above has %d Characters\n",op_len-1);

        op_len=0; //so that can be resused for next input line...

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

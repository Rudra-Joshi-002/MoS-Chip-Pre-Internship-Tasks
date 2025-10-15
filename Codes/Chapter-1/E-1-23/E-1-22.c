/*

Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.

Which Means

Read input text and wrap (fold) long lines so that no output line exceeds a given column width n.
Whenever possible, break (insert a newline) after the last non-blank character that occurs before column n. If there are no blanks/tabs to break on 
before column n, do something intelligent (see options below) so you still produce lines no longer than n (or as sensible).

*/

#include<stdio.h>

#define MAXLINE 100

int getLine(char [],int);

int main()
{
    int last_blank_tab,col,line_len,col_limit;

    char ip[MAXLINE];

    last_blank_tab=col=line_len=0;

    col_limit=30; //This is start folding/warping as number of characters exceeds 30...

     while((line_len=(getLine(ip,MAXLINE)))>0)
     {

        printf("\nThe Entered Line has %d Characters\n",line_len);

        printf("\nNow replacing the entered line with appropriate folded or warped lines gives:\n\n");

        int i=0;

        while(col<line_len)
        {
            for(i=col ; i<col+col_limit && i<line_len ;i++)
            {
                if(ip[i]==' ' || ip[i]=='\t')
                    last_blank_tab=i;
            }

            if(last_blank_tab!=0)
            {
                //now check if the starting character have spaces or tabs or anything

                int j=col;

                while(ip[j]==' ' || ip[j]=='\t')
                    j++;

                //this helps us know wheter the starting of a line has blanks or not if it has then 
                //they are not to be printed
                //thus printing starts from 1st non blank character upto last_blank_tab value
                while(j<last_blank_tab)
                    putchar(ip[j++]);

                //after transerversing the next time transerversing should being at last_blank_tab+1
                col=last_blank_tab+1;
                last_blank_tab=0;

            }
            //this is happens when all 30 input characters transversed has no blanks or tabs in them
            else
            {
                for(i=col ; i<col+col_limit && i<line_len ; i++)
                    putchar(ip[i]);

                col=i;
            }

            putchar('\n');

        
        }

        break;

     }

     printf("\nThank you that's all this program has already wasted maybe 6hrs of my day but yes at last proper output is there");

    
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

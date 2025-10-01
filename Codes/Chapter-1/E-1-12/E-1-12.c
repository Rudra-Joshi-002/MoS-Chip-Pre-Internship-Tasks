//Exercise 1-12. Write a program that prints its input one word per line.

#include<stdio.h>

#define IN 1
#define OUT 0

void main()
{
    int c,nl,nc,nw,state;

    nl=nc=nw=state=0;

    while((c=getchar())!=EOF)
    {   
        nc++;

        if(c=='\n')
            nl++;

        if(c==' ' || c=='\t' || c=='\n') //word definition condition check
            state=OUT;

        else if(state==OUT) //condition to check start of new word
        {
           state=IN;
           nw++;
           putchar('\n'); //to print a word at a new line
           putchar(c); //to print the 1st char of new word 
        }

        else
            putchar(c); //if its niether new line, tab or blank or start of new word then
                        //print as is i.e. the word

    }

    printf("\nNo. of Characters: %d, No. of Lines: %d, No. of Words:%d\n",nc,nl,nw);
    printf("EOF Encountered Terminating Program Now...\n");

}

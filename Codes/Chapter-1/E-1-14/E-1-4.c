//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
//in its input.

#include<stdio.h>

#define IN 1
#define OUT 0

void main()
{
    int c,nw,state,i=-1;//i is negative because at the occurence of very 1st word pre-increment happens***This is Imp to Understand
    int word_len[100]={}; //declaring an arrary where each element of an array stores the length of word 
                       //i.e. number of characters in a word starting from very 1st word encountered in
                       //i/p till last

    nw=state=0;

    while((c=getchar())!=EOF && i<100)
    {   

        if(c==' ' || c=='\t' || c=='\n') //word definition condition check
            state=OUT;

        else if(state==OUT) //condition to check start of new word
        {
           state=IN;
           nw++;
           word_len[(++i)]++; //at start of new word incerement index for new word enter and then 
                              //increment element associated with that word 
        }

        else
            word_len[i]++; //if neither blank or start of new word then just increment word_len at given
                           //index

    }
    
    //the following is the code for a horizontal histogram

    printf("\nNow Printing Info in form of Histogram...\n");

    for(int i=nw; i>0; i--)
    {
        printf("Word: %d | ",i);

        for(int j=0; j<word_len[i-1]; j++)
        {
            printf(" * "); //Histogram Bar Element
        }

        putchar('\n');
    }

    printf("Length: | "); //for printing the word length axis

    for(int i=1;i<=20;i++) //i=20 is a logical limit of word length of any word or atleast I hope that :)
    {
        printf(" %d ",i);
    }

    printf("\nEOF Encountered Terminating Program Now...\n");

}

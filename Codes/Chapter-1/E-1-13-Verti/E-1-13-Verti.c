//Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
//easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

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
            word_len[i]++; //if neither blank nor start of new word then just increment word_len at given
                           //index

    }
    
    //the following is the code for a horizontal histogram

    printf("\nNow Printing Info in form of Vertical Histogram...\n");
    printf("Y-Axis (Word Length)\n");
    for(int i=20 ; i>0 ; i--) //Logical length of any word hope so atleast :)
    {
        printf("%d: ",i);

        for(int j=0; j<nw ; j++)
        {
            if(i<=word_len[j]) //if for a given word length tarnseverse array and if value at the
                               //element in array is less than or equal to len no. i then print element
                printf(" * "); //else print blank this way whole graph is generated with spaces as chars
            else
                printf("   ");

        }

        printf("\n"); //skip to next line after one row is over

    }
    
    printf("0: ");

    for(int i=1;i<=nw;i++)
        printf(" %d ",i);

    printf(" X-Axis (Number of Words)\n");
    
    printf("\nEOF Encountered Terminating Program Now...\n");

}

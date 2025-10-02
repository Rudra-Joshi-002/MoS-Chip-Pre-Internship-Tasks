//Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
//in its input.

#include<stdio.h>

void main()
{
    int c;
    int char_freq[128]={};//declaring an arrary where each element of an array stores the occurence of diff
                         // charcters of ascii 
                        //i.e. number of characters in the entire i/p text

    while((c=getchar())!=EOF)
    {   
        if(c<128)
            char_freq[c]++;


    }
    
    //the following is the code for a vertical histogram

    printf("\nNow Printing Info in form of Vertical Histogram...\n");
    printf("Y-Axis (Frequencies of Characters)\n");
    for(int i=30 ; i>0 ; i--) //Logical length of any SHORT I/P Stream for Testing hope so atleast :)
    {
        printf("%d: ",i);

        for(int j=0; j<128 ; j++)
        {
            if(i<=char_freq[j]) //if for a given freq. no. tarnseverse array and if value at the
                printf(" * "); //element in array is less than or equal to len no. i then print element
                               //else print blank this way whole graph is generated with spaces as chars
            else
                printf("   ");

        }

        printf("\n"); //skip to next line after one row is over

    }
    
    printf("0: ");

    for(int i=1;i<=127;i++)
        printf(" %d ",i);

    printf(" X-Axis (Number of Characters)\n");
    
    printf("\nEOF Encountered Terminating Program Now...\n");

}

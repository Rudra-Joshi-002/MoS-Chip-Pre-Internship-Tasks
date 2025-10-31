/*

This file contains and defines the main function asssociated with the program   

Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
    
    tail -n

prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.

This modification will be made on the code of exercise-5-7 only because that already fills the sorting and storage 
requirments mentioned in the program

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lines.h" //include the header file defined by us

char *lineptr[MAXLINES];

int main(int argc , char *argv[])
{
    int storage_size=MAXLINES*MAXLEN; //define a variable that will hold max input accepted by program
    char storage[storage_size]; //define and assign memory equal to max input that can be accepted in form of array
    
    int lastlines=10; //default value of number of last lines to be printed if argc<2
    
    int nlines; //define a variable to count to number of lines that have currently been inputted
              
    //printing the values of argc and argv recieved from command line
    printf("The Number of Arugements Recieved From Command Line are %d\n",argc);

    printf("\nThe Arguments which were Recieved Are:\n");

    for(int i=0 ; i<argc ; i++)
        printf("\n%d: %s\n",i+1,argv[i]);
    
    //provision to handle too many arguments
    if(argc>2)
    {
        printf("\nToo many Arguments Expected atmost 2 recieved %d\n",argc);
        return 0;
    }
    
    printf("\nEnter a set of Lines after you are done press ctrl+d to Stop taking input:\n");

    if((nlines=readlines(lineptr,MAXLINES,storage,storage_size))>=0) //take input of number lines and if they are >=0
    {
        qsort_ud(lineptr,0,nlines-1); //sort the lines in descending order
    }

    else
        printf("\nInput to Big to Sort\n");
    
    //to set the numeber of last lines to be printed if agrc is not 1
    if(argc!=1)
    {
        int number=0;
        int len_arg=strlen(argv[1]); //finding the length of string argument argv[1]
        char *p=argv[1]; //pass the address of 1st of char of string agrv[1] points to
        
        //if 1st char of 2nd argument is not - then report error and exit
        if(p[0] != '-')
        {
            printf("\nEntered Argument Invalid Entered expected -num recieved %s\n",p);
            return 0;
        }

        for(int i=1 ; i<len_arg ; i++)
        {
           if(isdigit(p[i]))
           {
                number= number  *10 + (p[i] - '0'); //to store the argument number entered
           }

           else
           {
               printf("\nValue after - is not a integer recieved argument %s\n",argv[1]);
               return 0;
           } 
        }

        printf("\nEntered Number in Argument after - is %d\n",number);

        lastlines=number;
    
    }
    
    //making provision if entered number is greater than total lines inputted
    if(lastlines>nlines)
    {
        printf("\nThe Number in argument is greater than total lines entered hence displaying all lines\n");
        writelines(lineptr,nlines);
    }
    else
    {
        printf("\nPrinting last %d lines from sorted input\n",lastlines);

        for(int i=nlines-lastlines ; i<nlines ; i++)
            printf("\n%s\n",lineptr[i]);
    }
    
    return 0;
}

/*

This file contains and defines the main function asssociated with the program   

Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?
*/

#include<stdio.h>
#include "lines.h" //include the header file defined by us

char *lineptr[MAXLINES];

int main()
{
    int storage_size=MAXLINES*MAXLEN; //define a variable that will hold max input accepted by program
    char storage[storage_size]; //define and assign memory equal to max input that can be accepted in form of array
    
    int nlines; //define a variable to count to number of lines that have currently been inputted
    
    printf("Enter a set of Lines after you are done press ctrl+d to Stop taking input:\n");

    if((nlines=readlines(lineptr,MAXLINES,storage,storage_size))>=0) //take input of number lines and if they are >=0
    {
        qsort(lineptr,0,nlines-1); //sort the lines in descending order
        printf("\nNow Printing the Result of Sorting the Entered Lines Lexiographically:\n"); 
        writelines(lineptr,nlines);//write the lines after sorting it
    }

    else
        printf("\nInput to Big to Sort\n");
    
    return 0;
}

/*

This file contains and defines the main function asssociated with the program   

Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.

*/

#include<stdio.h>
#include<string.h>
#include "lines.h" //include the header file defined by us

char *lineptr[MAXLINES];

int storage_size=MAXLINES*MAXLEN; //define a variable that will hold max input accepted by program
    
char storage[MAXLINES*MAXLEN]; //define and assign memory equal to max input that can be accepted in form of array

int main(int argc, char *argv[])
{
    int numeric=0; //variable to define which sorting is to be done if 1 then sort numerically

    int fold=0; //variable to define wether sorting will be case sensitive or case insensitive    
    
    int nlines; //define a variable to count to number of lines that have currently been inputted
    
    //set the numeric flag based on various possible values of agrv[1]

    if (argc > 1 && ( ( strcmp(argv[1], "-n") == 0) || ( strcmp(argv[1],"-fn") == 0 ) || ( strcmp(argv[1],"-nf") == 0  ) ) )
           numeric = 1;

    //set the numeric flag based on various possible values of agrv[1]

    if (argc > 1 && ( ( strcmp(argv[1], "-f") == 0) || ( strcmp(argv[1],"-fn") == 0 ) || ( strcmp(argv[1],"-nf") == 0  ) ) )
           fold = 1; 

    printf("Enter a set of Lines after you are done press ctrl+d to Stop taking input:\n");

    if((nlines=readlines(lineptr,MAXLINES,storage,storage_size))>=0) //take input of number lines and if they are >=0
    {
        //(void **) typecast is used to indicate linptr is pointer which points to array of pointers so treat accordingly
        qsort( (void **)lineptr, 0, nlines-1, fold ,( int (*) (void *, void *)  ) (numeric ? numcmp : strcmp) ); //sort the lines in descending order
        printf("\nNow Printing the Result of Sorting the Entered Lines:\n"); 
        writelines(lineptr,nlines);//write the lines after sorting it
    }

    else
        printf("\nInput to Big to Sort\n");
    
    return 0;
}

/*

This file contains and defines the main function asssociated with the program   

Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.

*/

#include<stdio.h>
#include<string.h>
#include "lines.h" //include the header file defined by us

char *lineptr[MAXLINES];

int main(int argc, char *argv[])
{
    int numeric=0; //variable to define which sorting is to be done if 1 then sort numerically

    int reverse=0; //variable to define the nature of sorting like ascending or descending if 1 then descending
    
    int storage_size=MAXLINES*MAXLEN; //define a variable that will hold max input accepted by program
    
    char storage[storage_size]; //define and assign memory equal to max input that can be accepted in form of array
    
    int nlines; //define a variable to count to number of lines that have currently been inputted
    
    //set the numeric flag based on various possible values of agrv[1]

    if (argc > 1 && ( ( strcmp(argv[1], "-n") == 0) || ( strcmp(argv[1],"-rn") == 0 ) || ( strcmp(argv[1],"-nr") == 0  ) ) )
           numeric = 1;

    //set the numeric flag based on various possible values of agrv[1]

    if (argc > 1 && ( ( strcmp(argv[1], "-r") == 0) || ( strcmp(argv[1],"-rn") == 0 ) || ( strcmp(argv[1],"-nr") == 0  ) ) )
           reverse = 1; 

    printf("Enter a set of Lines after you are done press ctrl+d to Stop taking input:\n");

    if((nlines=readlines(lineptr,MAXLINES,storage,storage_size))>=0) //take input of number lines and if they are >=0
    {
        //(void **) typecast is used to indicate linptr is pointer which points to array of pointers so treat accordingly
        qsort( (void **)lineptr, 0, nlines-1, reverse ,( int (*) (void *, void *)  ) (numeric ? numcmp : strcmp) ); //sort the lines in descending order
        printf("\nNow Printing the Result of Sorting the Entered Lines Lexiographically:\n"); 
        writelines(lineptr,nlines);//write the lines after sorting it
    }

    else
        printf("\nInput to Big to Sort\n");
    
    return 0;
}

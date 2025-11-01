/*

This file contains and defines the main function asssociated with the program   

Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.

*/

#include<stdio.h>
#include "lines.h" //include the header file defined by us

char *lineptr[MAXLINES];

int storage_size=MAXLINES*MAXLEN; //define a variable that will hold max input accepted by program
    
char storage[MAXLINES*MAXLEN]; //define and assign memory equal to max input that can be accepted in form of array

//Global flags for sorting options.
//These are defined here without 'static' so they are globally accessible
//to other files like charcmp.c that need to read them.

int numeric = 0; // if 1, sort numerically
int fold = 0;    // if 1, fold upper/lower case
int directory = 0; // if 1, use directory order

int main(int argc, char *argv[])
{
    int nlines; //define a variable to count to number of lines that have currently been inputted
    int c; // variable to hold each character-based flag

    printf("Enter a set of Lines after you are done press ctrl+d to Stop taking input:\n");
    
    //argument parsing loop.
    //This loop iterates through all arguments argv[1], argv[2], etc.
    //that start with a '-'. It can handle combined flags like -nfd.
    
    //argv pts to -> array of char ptrs ->the char ptrs point to string passed as argument
    //so argv is a pointer to a pointer
    
    int i=1; //helps in parsing through *argv[] which contains pointers to string argument entered
    int j=0; //help through parse the string which pointers in *argv[] points to 
    
    while (--argc > 0 && argv[i][j]=='-' ) {
        // Loop through each character within a argument
        while ( (c = argv[i][++j]) ) {
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                case 'd':
                    directory = 1;
                    break;
                default:
                    printf("Error: unknown option %c\n", c);
                    argc = 0; // Stop processing
                    return -1; // Indicate error
            }
        }
        
        j=0;//setting j to zero so that next time 1st char of next string is fetched properly
        i++;//to pint to next argument of agrv[]
    }
    // At this point, argc and argv are positioned at any non-flag arguments

    if((nlines=readlines(lineptr,MAXLINES,storage,storage_size))>=0) //take input of number lines and if they are >=0
    {
        //We pass numcmp if numeric is 1, otherwise we pass our
        //new charcmp function, which will handle fold and directory flags internally

        qsort( (void **)lineptr, 0, nlines-1, ( int (*) (void *, void *)  ) (numeric ? numcmp : charcmp) ); 
        
        printf("\nNow Printing the Result of Sorting the Entered Lines:\n"); 
        writelines(lineptr,nlines);//write the lines after sorting it
    }
    else
        printf("\nInput to Big to Sort\n");
    
    return 0;
}

/*

This file contains the definition of function writelines

*/

#include<stdio.h>
#include"lines.h"

void writelines(char *lineptr[],int nlines)
{
    while(nlines-- >0) //while number of lines to be printed are greater than 0
    {
        printf("\n%s\n",*lineptr++); //print the lines as per what ptr in linptr array points to
    }

}

/*

This file contains the definition of function readline as per appropriate modification asked in exercise

*/

#include<stdio.h>
#include<string.h>
#include"lines.h"

int getLine(char *,int);

int readlines(char *lineptr[], int maxlines, char *storage ,int storage_size)
{
   int len, nlines=0;
   char line[MAXLEN];
   
   char *bufp = storage; //write the address of 1st element of storage array to bufp
   char *bufend = storage + storage_size ; //write the address of last element of storage array in bufend

   while((len=getLine(line,MAXLEN))>0)
   {
        if(nlines>=maxlines) return-1; //if no of lines is greater than -1 then break
        
        if(bufp + len + 1 > bufend) return -1; //if the storage is full then break

        strcpy(bufp,line); //if none of above condition is true then store then copy the line form start of bufp
        
        lineptr[nlines++]=bufp; //pass the pointer to the input string in storage to one of elements of lineptr
        
        //len+1 to include null char and point new poisition
        bufp +=(len+1);
   }

 return nlines; //at the end of reading return total lines read to the calling function 
}

//getline implemented with pointers

int getLine(char *s, int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n'){
        *s++ = c;
        i++;
    }
    
    *s  = '\0';

    //This returns the length *excluding* the '\0' char
    return i; 
    
}

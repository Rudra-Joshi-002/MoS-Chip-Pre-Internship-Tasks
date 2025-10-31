/*

This file contains the definition of function qsort
and swap

*/

#include<string.h>
#include"lines.h"

void qsort_ud(char *lineptr[], int left, int right)
{
    void swap(char *v[],int i, int j); //decalre the sort function which we will use later here
    
    int i,last;

    if(left>=right) //if the number of elements are less than to eat 5-star and do nothing ;)
     return;
    
    swap(lineptr,left,(right+left)/2); //partition element is choosen as median of array and placed at start of array

    last=left; //putting the piviot index at start of array which contains the partition element

    for(i=left+1 ; i<=right ; i++)
     if(strcmp(lineptr[i],lineptr[left])<0) //if the value of string at index i is less than at partition element string   
        swap(lineptr,++last,i); //then swap the string ptrs of piviot and index elements

    swap(lineptr,left,last); //after array has been transversed place partition element to its appropriate index

    qsort_ud(lineptr,left,last-1); //now apply recursive calls to further sort the array
    qsort_ud(lineptr,last+1,right);
}

void swap(char *v[],int i,int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;

}

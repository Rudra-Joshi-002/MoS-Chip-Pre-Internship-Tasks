/*

This file contains the definition of function qsort
and swap

*/

//defining a generic qsort using generic pointer arguments (void *) to handle sorting for any datatype

#include"lines.h"

void qsort(void *v[], int left, int right, int fold,int (*comp) (void *, void *))
{
    void swap(void *v[],int i, int j); //decalre the sort function which we will use later here
    
    int i,last;

    if(left>=right) //if the number of elements are less than to eat 5-star and do nothing ;)
     return;
    
    swap(v,left,(right+left)/2); //partition element is choosen as median of array and placed at start of array

    last=left; //putting the piviot index at start of array which contains the partition element

    for(i=left+1 ; i<=right ; i++)
    {
        if( ( (*comp) (v[i],v[left]) ) < 0 ) //if the value of datatype at index i is less than at partition element string   
             swap(v,++last,i); //then swap the particular data type ptrs of piviot and index elements

    }
    swap(v,left,last); //after array has been transversed place partition element to its appropriate index

    qsort(v,left,last-1,fold,comp); //now apply recursive calls to further sort the array
    qsort(v,last+1,right,fold,comp);
}

void swap(void *v[],int i,int j)
{
    char *temp;

    temp=v[i];
    v[i]=v[j];
    v[j]=temp;

}

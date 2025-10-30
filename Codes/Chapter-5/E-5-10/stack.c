/*
This is a file named stack.c that contains all the variables and function definitions
associated with stack operations

*/

#include<stdio.h>
#include"calc.h"

#define MAXVAL 100 //defines the max depth of value_stack

int sp=0; //points to the next free value in value_stack

double val[MAXVAL]; //define value_stack 

//defining push function here

void push(double f)
{
    if(sp<MAXVAL)
        val[sp++]=f;

    else
        printf("\nStack has overflown cannot push variable f: %g\n",f);

}

//defining pop function here

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
        printf("\nError Stack is Empty\n");

    return 0;
}

//defining the peek function here

void peek(void)
{
    if(sp<MAXVAL && sp>0)
    {
        printf("\nThe Value at Top of Stack is : %g\n",val[sp-1]);//return value at top of stack
    }

    else
        printf("\nStack is Empty No Value to Print\n");
}

//defining duplicate function here

void duplicate(void)
{
    if(sp<MAXVAL && sp>0)
    {
        printf("\nPrinting now the top two values of stack Before Duplicating\n");

        for(int i=sp-1,j=0 ; j<2 ;j++)
           printf("\n sp: %d , value at sp: %g\n",i-j,val[i-j]);  

        printf("\nDuplicating the Value at Top of stack\n");

        val[sp]=val[sp-1];
        sp++;//increment sp to point to next free value
        
        printf("\nPrinting now the top two values of stack after Duplicating\n");

        for(int i=sp-1,j=0 ; j<2 ;j++)
           printf("\n sp: %d , value at sp: %g\n",i-j,val[i-j]); 
    }

    else
        printf("\nStack is Empty no Value to Duplicate\n");

}

//defining swap function here

void swap(void)
{
    if(sp<MAXVAL && sp>0)
    {
        printf("\nPrinting now the top two values of stack Before Swapping\n");

        for(int i=sp-1,j=0 ; j<2 ;j++)
           printf("\n sp: %d , value at sp: %g\n",i-j,val[i-j]);  

        printf("\nSwapping the Value at Top of stack\n");

        double temp;

        temp=val[sp-1];//put the top value of stack in temp
        val[sp-1]=val[sp-2];//swap top value of stack with one value below it
        val[sp-2]=temp;
        
        printf("\nPrinting now the top two values of stack after Swapping\n");

        for(int i=sp-1,j=0 ; j<2 ;j++)
           printf("\n sp: %d , value at sp: %g\n",i-j,val[i-j]); 
    }

    else
        printf("\nStack is Empty no Value to Swap\n");

}

//defining clear function here

void clear(void)
{
     if(sp<MAXVAL && sp>0)
    {
        printf("\nPrinting now the values of stack Before Clearing\n");

        for(int i=sp-1,j=0 ; j<sp ;j++)
           printf("\n sp: %d , value at sp: %g\n",i-j,val[i-j]);  

        printf("\nClearing the Value of stack\n");

        sp=0;
        val[sp]='\0';
        
        printf("\nPrinting now the values of stack after Clearing\n");

        peek();
    }

    else
        printf("\nStack is Empty no Value to Clear\n");

   
}

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

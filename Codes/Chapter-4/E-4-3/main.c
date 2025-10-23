/*

Here we will split the calculator program  (that uses binary operators) into  several source files like
main.c
stack.c
getop.c
getch.c
calc.h

where improvements for a given exercise will be done in the part concerned with that file only

this style of programming is chosen so that I can get some experince on how to deal with program split
in between several files

now comming to the question of this exercise

Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers.

*/

#include <stdio.h>
#include <stdlib.h> //for atof
#include "calc.h" //where all declarations concerned with all the programs and #defines are written

#define MAXOP 100 //max size of operands or operators

//writing the main function of this project here which is Reverse Polish Calculator
int main()
{
    int type;
    double op2; //to hold the second operand in case of subtraction and division operations
    char s[MAXOP];
    
    printf("This is a reverse polish calculator currently supporting the following operations:\n");
    printf("\n1.Addition (+)\n2.Subtraction (-)\n3.Multiplication (*)\n4.Division (/)\n");
    printf("\nEnter your commands here:\n");

    while((type=getop(s))!=EOF)
    {
        switch(type){
        
            case NUMBER: 
                push(atof(s)); //push the number operand to stack
                break;

            case '+':
                push(pop()+pop()); //if operator==+ then add the two operands that it followed
                break;

            case '-':
                op2=pop();
                push(pop()-op2);
                break;

            case '*':
                push(pop()*pop());
                break;

            //adding provision for modulus operation
            //here if operands are real then they are type casted to int and the result is served

            case '%':
                op2=pop();
                push(((int)pop())%((int)op2));
                break;

            case '/':
                op2=pop();
                push(pop()/op2);
                break;
            
            case '\n':
                printf("\nResult of Operation is: %g\n",pop()); //if new line encountered means a line of calculation is entered
                break;

            default:
                printf("\nError Occured Unkonwn Command: %s\n",s);
                break;
        }
    }     

    return 0;
}   


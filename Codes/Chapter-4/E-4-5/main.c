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

Exercise 4-5. Add access to library functions like sin, exp, and pow. Use <math.h>
*/

#include <stdio.h>
#include <stdlib.h> //for atof
#include<math.h> //for this particular exercise
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
    printf("\n5.Peek (p) to print top element of stack without popping\n");
    printf("\n6.Duplicate (d) to Duplicate the top element of stack\n");
    printf("\n7.Swap (s) to Swap the two top elements of stack\n");
    printf("\n8.Clear (c) to clear the current stack\n");
    printf("\n9.Sine (sin)\n10.Exponent (exp)\n11.Power (pow)\n");
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
            
            //calling the stack related functions as asked in excercise
            case 'p':
                peek();
                break;

            case 'd':
                duplicate();
                break;
            
            case 's':
                swap();
                break;

            case 'c':
                clear();
                break;

            case SINE:
                push(sin(pop()));
                break;

            case EXP:
                push(exp(pop()));
                break;

            case POW:
                op2=pop();
                push(pow(pop(),op2));
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


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

Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.

here I've decided to implement at my design to terminate the program as soon as EOF is encountered
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
    double vars[26]; //array for storing variable values form A-Z
    double last=0; //variable to store the last printed value

    for(int i=0 ; i<26 ; i++)
        vars[i]=0; //initializing the array to zero at start


    printf("This is a reverse polish calculator currently supporting the following operations:\n");
    printf("\n1.Addition (+)\n2.Subtraction (-)\n3.Multiplication (*)\n4.Division (/)\n");
    printf("\n5.Peek (p) to print top element of stack without popping\n");
    printf("\n6.Duplicate (d) to Duplicate the top element of stack\n");
    printf("\n7.Swap (s) to Swap the two top elements of stack\n");
    printf("\n8.Clear (c) to clear the current stack\n");
    printf("\n9.Sine (sin)\n10.Exponent (exp)\n11.Power (pow)\n");
    printf("\n10.variable_name = [between A-Z Uppercase only] (e.g. 5 A = to assign a value of 5 to variable named 'A')\n");
    printf("\n11. v to print or use the most recently printed value\n");
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

            //adding cases concerned with variable names and last printed variable
            
            case VAR:

                 char name = s[0];   /* variable letter 'A'..'Z' */
                 int ch;

                 /* Peek next non-space character */
                 do {
                        ch = getch();
                 } while (ch != EOF && (ch == ' ' || ch == '\t'));

                 if (ch == '=') {
     
                    double val = pop();           /* pop value to assign */
                    vars[name - 'A'] = val;
                    push(val);                    /* push back so printing shows the assigned value if desired */
                } 
                
                else {
                    /* not an assignment: push back the char and push variable's value */
                    ungetch(ch);                  /* restore the char we peeked */
                    push(vars[name - 'A']);       /* push variable's current value */
                }
            
               break;

            case 'v':
                push(last); //push last variable that was printed on stack for any operations that came up
                printf("\nThe Value of Last Printed Variable is %g\n",last);
                break;

            case '\n':
                printf("\nResult of Operation is: %g\n",pop());//if new line encountered means a line of calculation is entered
                break;

            default:
                printf("\nError Occured Unkonwn Command: %s\n",s);
                break;
        }
    }

    printf("\nEOF Encountered Terminating the Program Now...\n");    

    return 0;
}   


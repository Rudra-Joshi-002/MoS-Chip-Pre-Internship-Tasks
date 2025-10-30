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

Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
    expr 2 3 4 + *
evaluates 2 * (3+4).

Okay.... So Let's discuss the approach we'll choose here

Since we have to make a command line version of RPN what we'll do is that we'll have list of operators and operands
in *argv[] which will upload to char BUFFER[] associated with getch() and ungetch() using ungetch()

next we will modify getch() to only read from the buffer and hopefully this will save me time of rewritng the whole
program from scratch again since we only use the program to give arguments from command line so I think it should not be an
issue to any one

I mean this program may just showcase my programmers Lazyness... :)

*/

#include <stdio.h>
#include <stdlib.h> //for atof
#include<string.h>
#include<math.h> //for this particular exercise
#include "calc.h" //where all declarations concerned with all the programs and #defines are written

#define MAXOP 100 //max size of operands or operators

//writing the main function of this project here which is Reverse Polish Calculator
int main(int argc, char *argv[])
{
    int type;
    double op2; //to hold the second operand in case of subtraction and division operations
    char s[MAXOP];
    

    //printing the values of argc and argv recieved from command line
    printf("The Number of Arugements Recieved From Command Line are %d\n",argc);

    printf("\nThe Arguments which were Recieved Are:\n");

    for(int i=0 ; i<argc ; i++)
        printf("\n%d: %s\n",i+1,argv[i]);
    
    //uploading the values obtained from command line into char buffer using ungetch()
   
    ungetch( '\n' ); //since buffer acts like LIFO stack therefore pushing newline character 1st to indicate end of expression when it appears
    
    for(int i=argc-1 ; i>0 ; i--) // -1 to ensure that argumets uptill only operators and operands reaches the buffer
    {   
        char *p = argv[i]; //since argv is a pointer to the string we are passing this address to another pointer for later processing

        for (int j=strlen(p)-1 ; j>-1 ; j-- ) //len of string contained in what current argv contained is found and pushed to buffer char at time
                ungetch((int) p[j]);
            
        ungetch( ' ' ); //once and entire argument which may be a operand or operator is passed we pass ' ' to keep the token same as expected by
                        //get op of this code and as we passed arguments in previous exercise
    }
    
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


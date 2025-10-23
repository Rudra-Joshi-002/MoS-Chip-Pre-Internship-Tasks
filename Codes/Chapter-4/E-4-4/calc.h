/*
This is a header file calc.h which contains all function declearations of
all the functions which are defined across several source files for this project

this is written so that there is only one copy of declarations and #defines that needs
to be maintained (get and keep) right as the program evolves

*/

#define NUMBER '0' //serves as a signal that a number is found
void peek(void); //to print top stack element
void duplicate(void); //to duplicate the top stack element
void swap(void);//to swap two of top stack elements
void clear(void);//to clear the stack
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

/*
This is a header file calc.h which contains all function declearations of
all the functions which are defined across several source files for this project

this is written so that there is only one copy of declarations and #defines that needs
to be maintained (get and keep) right as the program evolves

*/

#define NUMBER '0' //serves as a signal that a number is found
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

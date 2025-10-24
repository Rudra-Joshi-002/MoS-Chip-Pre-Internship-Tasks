/*
This file has all the definitions of functions and variables associated with getop
whose job is to collect the entered characters and classify them as digits and non-digits 
and return appropriate signals
*/

#include<stdio.h>
#include<ctype.h>
#include"calc.h"

int getop(char s[])
{
    int i,c;

    while((s[0]=c=getch())==' ' || c=='\t'); //skip whitespaces and tabs if any

    s[1]='\0'; //terminate the loop and string at 1st non blank or non tab char
    
    i=0;

    //logic to check for a variable

    if(isalpha(c) && isupper(c) && !isdigit(c))
    {
        return VAR;
    }

    //logic to check if a negative operand is entered by the user

    if(s[0]=='-')
    {   
        c=getch();
        //if the next input char fetched is part of number then keep fetching that number later in code
        if( isdigit(c) || c=='.')
            s[++i]=c;
        
        //but if the next input char fetched is not part of the number it means that the -ve sign used
        //here is for binary operator and thus we must unget the peeked/fetched char after 1st -ve sign
        //and return '-' to indicate the case ladder of the binary operation to be performed
        else
        {
            ungetch(c);
            return '-';
        }

    }
    
    //check for sine operator
    if(s[0]=='s')
    {
        c=getch();

        if(c=='i')
        {
            c=getch();

            if(c=='n')
                return SINE;
            else
                return c; //this will cause error in expression
        }

        else
        {
            ungetch(c); //if peeked char is not 'i' then unget it and return 's' since that maybe for swap func
            return 's';
        }


    }

    //check for exponent operator
    if(s[0]=='e')
    {
        c=getch();

        if(c=='x')
        {
            c=getch();

            if(c=='p')
                return EXP;
            else
                return c;
        }

        return c;
    }

    //check for power operator
    if(s[0]=='p')
    {
        c=getch();

        if(c=='o')
        {
            c=getch();

            if(c=='w')
                return POW;
            else
                return c;
        }

        else
        {
            ungetch(c); //if next char after 'p' is not 'o' then p may correspond to peek command so we return p in that case
            return 'p';
        }
    }

    if(!isdigit(c) && c!='.') //if c is not a digit nor a decimal point then it maybe some 
        return c; //valid operand or some invalid character so we return it from here so that the case ladder decide accordingly
    
    //now if not any valid or invalid character then

    //now if c is checked if its not '.'
    if(isdigit(c)) //if its a digit then keep on collecting it until non digit character is encountered
        while(isdigit(s[++i]=c=getch()));

    if(c=='.') //if the non digit character is decimal point then continue taking the input stream
        while(isdigit(s[++i]=c=getch()));
    
    s[i]='\0';//that is if non digit is obtd after fetching i/p stream then stop taking i/p from that point on

    if(c!=EOF) //this checks if the fetched character is eof if its not it means its newline char and we must unget it for later
        ungetch(c);
    
    return NUMBER; //after clearing all levels of test to classify as a digit and after those digits have been entered
                   //then return NUMBER as a signal to case lader that the type of input collected is a number and is to
                   //be dealt accordingly

} 

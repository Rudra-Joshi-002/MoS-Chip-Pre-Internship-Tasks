/*
Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.

here for this program we will try to satisfy the following Testcases:

Example test cases

"123.45" -> 123.45

"-0.001" -> -0.001

"6.022e23" -> 6.022 × 10^23

"3.14E-2" -> 0.0314

" +.5e+2 " -> 50.0
*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define MAXLINE 100

void getLine(char line[], int max);

double atof(char []);

int main()
{
    double ans;
    char s[MAXLINE];

    printf("Enter any number:\n");
    getLine(s,MAXLINE);

    printf("\nEntered Number is: %s",s);

    ans=atof(s);

    printf("\nNow printing the answer of string number converted to floating point:\n%lf\n",ans);

    return 0;
}

//implementing the required atof func

double atof(char s[])
{
    int i,j,power_after_decimal=1;
    int sign=1;
    int exponent_sign=1;
    int after_exponent_val=0;
    double val=0;

    //skip leading white spaces or tabs
    
    for(i=0 ; s[i]==' ' || s[i]=='\t' ; i++);

    //logic for 1st non-blank and non-tab character
    //if 1st non-blank is -ve then change sign
    if(!isdigit(s[i]))
    {
        if(s[i]=='-')
            sign=-1;
        
        else if(s[i]=='+'); //do nothing
        //if 1st non-whitespace is neither of the sign the input is wrong so return from it
        else
        {
            printf("\nWrong Input Entered\n");
            return -1;
        }
       
       //and if it is any of the signs then increment the index to point to next char in array
       i++; 
            
    }


    for(i=i ; isdigit(s[i]) ; i++)
    {    
        val=val*10+(s[i]-'0');
    }
    
    //check if the next non-digit character is a decimal point or full stop
    if(s[i]=='.')
    {
        i++;

        for(i=i ; isdigit(s[i]) ; i++)
        {
            val=val*10+(s[i]-'0');
            power_after_decimal*=10;
        }
    }

    //check if the next non-digit is a exponent or not if it is then increment the index the fetch the next char
    
    if(s[i]=='e' || s[i]=='E')
    {
        i++;
         
        if(!isdigit(s[i]))
        {
            if(s[i]=='-')
               exponent_sign=-1;
        
            else if(s[i]=='+'); //do nothing
            
            //if 1st non-whitespace is neither of the sign the input is wrong so return from it
            else
            {
                printf("\nWrong Input Entered\n");
                return -1;
            }
       
            //and if it is any of the signs then increment the index to point to next char in array
            i++; 
            
        }
        
        //this loop collects the number after exponent
        for(i=i ; isdigit(s[i]) ; i++)
            after_exponent_val=after_exponent_val*10+(s[i]-'0');

    }

    return (val*sign*pow(10,(after_exponent_val*exponent_sign)))/(power_after_decimal);

}

//simple function to get a line

void getLine(char s[], int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';
    
}

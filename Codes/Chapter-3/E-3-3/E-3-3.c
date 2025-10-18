/*
Exercise->3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the->string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
and->digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading->or trailing - is taken literally.

for->reference our program will try to stay true to following test cases

Example->test cases

s1->= "a-d" ->s2 = "abcd".

s1->= "a-b-c" ->s2 = "abc" (if following common left-to-right rule).

s1->= "-a-z" ->s2 = "-abcdefghijklmnopqrstuvwxyz".

s1->= "a-z0-3" ->s2 = "abcdefghijklmnopqrstuvwxyz0123".

s1->= "z-a" ->s2 = "z-a" (no expansion).

s1->= "A-Cx1-3" ->s2 = "ABCx123"

Constraints->& assumptions

Only->expand when left and right endpoints are both digits or both lowercase letters or both 
uppercase->letters and left ≤ right (i.e., a-z).

If->the range is reversed like z-a, treat it as literal z-a (i.e., do not expand)

Leading->- or trailing - (i.e., -a or z-) should be copied literally.
*/

#include<stdio.h>

#define MAXLINE 100

void getLine(char [], int );

void expand(char [], char[]);

int main()
{
    //very straight forward hope no need of explanations here :) ...

    char s1[MAXLINE],s2[MAXLINE];

    printf("Enter a String:\n");
    getLine(s1,MAXLINE);

    printf("\nEntered String is:\n%s",s1);

    printf("\nCalling expand()...\n");

    expand(s1,s2);

    printf("\nPrinting s2:\n%s",s2);

    return 0;
}

//now implenting the expand as per things mentioned in above block of comments

void expand(char s1[], char s2[])
{
    int i,j=0;

    for(i=0 ; s1[i]!='\0' ; i++)
    {
        if( s1[i]=='-')
        {   
            //at detection of - check if prev and next element adjacent to -
            //are lower case and prev_element<next_element
            if( s1[i-1]>='a'&& s1[i+1]<='z' && s1[i-1]<s1[i+1])
            {   
                //store the numerical value of character begining from the chronologically next character 
                //from prev till one less than next
                for(int k=s1[i-1]+1 ; k<s1[i+1] ; k++)
                    s2[j++]=k;
            }
           
            //same logic as above but now just for upper case letters 
            else if( s1[i-1]>='A' && s1[i+1]<='Z' && s1[i-1]<s1[i+1] )
            {
                for(int k=s1[i-1]+1 ; k<s1[i+1] ; k++)
                    s2[j++]=k;
            }
            
            //same logic applied for digits 0-9
            else if( s1[i-1]>='0' && s1[i+1]<='9' && s1[i-1]<s1[i+1])
            {
                for(int k=s1[i-1]+1 ; k<s1[i+1] ; k++)
                    s2[j++]=k;
            }

            //if none of the conditions of either lowercase or upper case or digits satisfy
            //then it mean that - is either a trailing or a leading - and hence is to be taken literllay
            else
                s2[j++]=s1[i];
        }

        else
            s2[j++]=s1[i];
    }

    s2[j]='\0'; //add null as strings end
}

//simple function to take a line input

void getLine(char ip[],int lim)
{
    int i,c;

    for(i=0; i<lim-1 && (c=(getchar()))!= EOF && c!='\n' ; i++)
    {
        ip[i]=c;
    }

    if(c=='\n') //if new line character is entered
    {
        ip[i++]='\n';
        ip[i]='\0';
    }

    else //else either EOF encountered or Line Buffer Got Full
    {
        ip[i]='\0';
    }

}

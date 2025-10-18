/*

Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.

*/

#include<stdio.h>

#define MAXLINE 100

void getLine(char [],int);

void escape(char [],char []);

void unescape(char [],char []);

int main()
{
    //very straight forward hope no need of explanations here :) ...

    char s[MAXLINE],t[MAXLINE];

    printf("Enter a String:\n");
    getLine(t,MAXLINE);

    printf("\nEntered String is:\n%s",t);

    printf("\nCalling escape()...\n");

    escape(s,t);

    printf("\nPrinting s:\n%s",s);
    
    printf("\nEnter a String with escape sequnces in it:\n");
    getLine(t,MAXLINE);

    printf("\nEntered String is:\n%s",t);

    printf("\nCalling unescape()...\n");

    unescape(s,t);

    printf("\nPrinting s:\n%s",s);

    return 0;
}


//escape function implemented here

void escape(char s[],char t[])
{   
    int i,j=0;//j is maintained to copy to t into s properly with a required escape sequnce
              //and make indexing logic little less painfull...

    for(i=0 ; t[i]!='\0' ;i++)
    {
        switch(t[i])
        {
            //if newline is detected
            case '\n':
                s[j++]='\\';
                s[j++]='n';
                break;
            //if tab is detected
            case '\t':
                s[j++]='\\';
                s[j++]='t';
                break;
            //is \ is detected
            case '\\':
                s[j++]='\\';
                s[j++]='\\';
                break;

            default:
                s[j++]=t[i];
                break;
            
        }

    }

    s[j]='\0'; //to add null char in the copied string
}

//now implementing unescape

void unescape(char s[],char t[])
{   
    int i,j=0;//j is maintained to copy to t into s properly with a required escape sequnce
              //and make indexing logic little less painfull...
    
    for(i=0 ; t[i]!='\0' ; i++)
    {
        if(t[i]=='\\')
        {
            //index incremented to fetch the next char after occurence of a backslash

            switch(t[++i])
            {
                case 'n':
                    s[j++]='\n'; //insert a new line char
                    break;

                case 't':
                    s[j++]='\t'; //insert a tab
                    break;

                default:
                    s[j++]='\\'; //insert a backslash
            }
        }
        
        else
             s[j++]=t[i]; //if condition false then carry normal copy operations
    }

    s[j]='\0'; //terminate the string with a null

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

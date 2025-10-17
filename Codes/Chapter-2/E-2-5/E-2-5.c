/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/


#include<stdio.h>

void getLine(char [],int );

int any(char [],char []);

int main()
{
    int ans,lim=100;

    char s1[lim],s2[lim]; 

    printf("Enter a string:\n");
    getLine(s1,lim);

    printf("\nEnter another string:\n");
    getLine(s2,lim);
    
    ans=any(s1,s2);
    
    printf("\nAns: %d\n",ans);  

    return 0;
}

//implementing any function here

int any(char s1[],char s2[])
{
    for(int i=0 ; s2[i]!='\0' ; i++)
    {
        for(int j=0 ; s1[j]!='\0' ; j++)
        {   
            //if any character in s2 matches s1 then return the index of 1st match
            if(s1[j]==s2[i])
                return j;
        }

    }

    printf("\nReturning from any without any match\n");
    //return -1 if no matches are found in s1 for any charcter in s2
    return -1;
    
}

//simple function to take a line input

void getLine(char ip[],int lim)
{
    int i,c;

    for(i=0; i<lim-1 && (c=(getchar()))!= EOF && c!='\n' ; i++)
    {
        ip[i]=c;
    }

    ip[i]='\0';
    
}

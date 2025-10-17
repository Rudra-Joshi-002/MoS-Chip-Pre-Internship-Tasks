/*
Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.
*/

#include<stdio.h>

void squeeze(char [],char[]);
void getLine(char [],int);

int main()
{
    int lim=100;
    char s1[lim],s2[lim],out[lim];

    printf("Enter A String:\n");
    getLine(s1,lim);

    printf("\nEnter Another String:\n");
    getLine(s2,lim);
    
    printf("\nS1: %s\n",s1);
    
    squeeze(s1,s2);

    
    printf("\nS2: %s\n",s2);
    
    printf("\nS1 after Calling Squeeze: %s\n",s1);

    return 0;
}

//squeeze func implemented here

void squeeze(char s1[],char s2[])
{   
    //loop till null is not found in s2
    for(int i=0; s2[i]!='\0' ; i++)
    {
        int k=0;
        //similarly loop in s1
        for(int j=0 ; s1[j]!='\0' ; j++)
        {   
            //check if s1 are s2 have same characters
            if(s1[j]!=s2[i])
            {
                s1[k++]=s1[j]; //if not then store s1 in itself using another index 
                               //varaible k which helps in deletion of matched chars
            }   
            //this way we store in s1 those characters of s1 which doesn't match with
            //current char of s2 using another variable ('k' here) that is not used
            //for looping around s1 this scheme allows us to skip the matched characters
            //while moving the unmatched characters towards right
        }
        s1[k]='\0';

    }
    
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

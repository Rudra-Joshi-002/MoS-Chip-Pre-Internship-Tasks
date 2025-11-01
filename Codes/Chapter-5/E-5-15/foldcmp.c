/*

This file contains the function defintion of user defined foldcmp function
which comapres two strings on case insensitive basis

*/

#include<ctype.h>

int foldcmp(char *p, char *q) //pass pointer to char string as arguments
{
    //parse the strings until null character is recieved and cmp strings while it isn't


    while( *p!='\0' || *q!='\0')
    {
        if( tolower(*p) == tolower(*q)  )//convert the char value to lowercase and check if same and continue
        {   
            //if not same then break and return the difference
            p++;
            q++;
        }
        else
            break;


    }
    
    return ( tolower(*p) - tolower(*q) );

}


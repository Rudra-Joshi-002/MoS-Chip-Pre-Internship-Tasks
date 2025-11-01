/*

This file contains the general definition of numeric comparision operator

*/

#include<stdlib.h>


int numcmp( void *p1 , void *p2)
{
    //We must cast the void pointers back to char* to use them 
    char *s1 = (char *)p1;
    char *s2 = (char *)p2;

    double v1,v2; //define two variables of double type to hold the numerical value of two strings

    v1=atof(s1); //convert the strings into a numerical value
    v2=atof(s2);

    //now just return flag integers to inidicate the result after comparision
    
    if(v1<v2)
        return -1;
    
    else if(v1==v2)
        return 0;
    
    else
        return 1;
}

/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include<stdio.h>
#include<string.h>

int htoi(char []);

int main()
{
    int c,i,lim=11;
    char ip[lim];
    
    int ans;

    printf("\nEnter a Hexadecimal number between 0x0-0xffffffff:\n");

    for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF ; i++)
        ip[i]=c;

    ip[i]='\0';

    ans=htoi(ip);

    printf("\nHexadecimal Number Entered: %s Equivalent Decimal Value: %d\n",ip,ans);    

    return 0;
}

int htoi(char ip[])
{
    unsigned int ans=0;


}


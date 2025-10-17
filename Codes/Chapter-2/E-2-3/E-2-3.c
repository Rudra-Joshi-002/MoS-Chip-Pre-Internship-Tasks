/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include<stdio.h>

int htoi(char []);

int main()
{
    int c,i,lim=12;
    char ip[lim];
    
    int ans;

    printf("\nEnter a Hexadecimal number between 0x0-0xffffffff:\n");

    for(i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF ; i++)
        ip[i]=c;

    ip[++i]='\0';

    ans=htoi(ip);

    if(ans>-1)
        printf("\nHexadecimal Number Entered: %s Equivalent Decimal Value: %d\n",ip,ans);    
    
    else
        printf("\nInvalid Number Entered");

    return 0;
}

int htoi(char ip[])
{
    unsigned int ans=0,num;

    if((ip[0]=='0') && (ip[1]=='x' || ip[1]=='X'))
    {
        for(int i=2; ip[i]!='\0';i++)
        {
            //condition the check for a valid hex number
            if((ip[i]>='0' && ip[i]<='9') || (ip[i]>='a' && ip[i]<='f') || (ip[i]>='A' && ip[i]<='F'))
            {   
                if(ip[i]>='0' && ip[i]<='9')
                    num=ip[i]-'0';
                
                else if(ip[i]>='a' && ip[i]<='f')
                    num=(ip[i]-('a'))+10;

                else
                    num=(ip[i]-('A'))+10;

                ans=ans*16+num;
            }

            else
                return -1;
        }

    }

    else
    {
        //i<8 beacuse we provide valid conversion only for a 32-bit hex number
        for(int i=0; i<8 && ip[i]!='\0';i++)
        {
            //condition the check for a valid hex number
            if((ip[i]>='0' && ip[i]<='9') || (ip[i]>='a' && ip[i]<='f') || (ip[i]>='A' && ip[i]<='F'))
            {
                if(ip[i]>='0' && ip[i]<='9')
                    num=ip[i]-'0';
                
                else if(ip[i]>='a' && ip[i]<='f')
                    num=(ip[i]-('a'))+10;

                else
                    num=(ip[i]-('A'))+10;

                ans=ans*16+num;
            }

            else
                return -1;
        }

    }

    return ans;
}


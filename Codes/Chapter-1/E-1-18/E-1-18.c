//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
//to delete entirely blank lines.

#include<stdio.h>

#define MAXLEN 100

int getLine(char [],int);

int proccess_line(char [],char[],int);

int main()
{
    char ip_line[MAXLEN],op_line[MAXLEN];
    int ip_len,op_len;

    ip_len=op_len=0;

    while((ip_len=getLine(ip_line,MAXLEN))>0)
    {
        printf("The Input Line Entered Has Length: %d\n",ip_len);
        printf("Printing the entered i/p line:\n");
        printf("%s\n",ip_line);

        printf("Now Calling Line Processing Funcx to Process i/p line as per problem statement\n");
        
        op_len=proccess_line(op_line,ip_line,ip_len); 

        printf("The Output Line Processed Has Length: %d\n",op_len);
        printf("Printing the processed o/p line:\n");
        printf("%s\n",op_line);
    }

    printf("\nEOF Encountered Exiting the Program Now...\n");

    return 0;

}

//simple func to take a line input from terminal

int getLine(char s[],int lim)
{
    int c,i=0;
    
    for(i=0; i<lim-1 && (c=(getchar()))!=EOF && c!='\n';i++)
    {
        s[i]=c;
    }

    if(c=='\n')
    {
        s[i++]=c;
    }

    s[i]='\0';

    return i;
}

//main line processing func
int proccess_line(char op[],char ip[],int ip_len)
{
    int i=ip_len-3; //because ip-1 = '\0' and ip-2='\n' as for standard line as per above getline logic
    int trail_counter=0;
    int j=0;

    while( ip[i]==' ' || ip[i]=='\t')
    {
        trail_counter++;//this counts the number of trailing characters between end of line and non space and non tab characters
        i--;
    }

    for(j=0;j<ip_len-1-trail_counter;j++)
        op[j]=ip[j];

    op[j]='\0';

    return j;

}


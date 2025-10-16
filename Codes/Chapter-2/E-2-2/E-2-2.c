/*Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

Where the for loop being talked about is the following

for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i]=c;

*/

#include<stdio.h>

#define MAXLINE 100

int main()
{
    int c,i,lim=MAXLINE;

    char s[MAXLINE];

    //first we implement the for loop given in question so that we can verify it with our 
    //loop equivalent results
    
    for(i=0 ; i<lim-1 && (c=getchar())!='\n' && c!=EOF ; i++)
        s[i]=c;
    
    s[i]='\0'; //insert null character at end of string inputted
    
    printf("\nPrinting the Entered String using for loop defined in Que:\n%s\n",s);

    //now let's implement our loop logic without using logical && or ||
    printf("\nNow Re-Enter the Same string entered earlier:\n");

    i=0;

    while(i<lim-1)
    {    
        while((c=getchar())!='\n')
        {
            if(c!=EOF)
            {
                s[i++]=c;
                break;
            }
            else
                break;

        }
       
       if(c=='\n')
       {
            s[i]='\0';
            break;
       }

       else if(c==EOF)
       {
           s[i]='\0';
           break;
       }
           

    }

    printf("\nNow Printing The String Taken as I/P from a Equivalent FOR loop Structure:\n%s\n",s);
    
    return 0;
}

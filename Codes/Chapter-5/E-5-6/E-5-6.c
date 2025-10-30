/*

Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4).

*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

void getLine(char *,int);
int strindex(char * ,char *);
void reverse(char *);
void itoa(unsigned int, char *);

int main()
{
    char s[MAXLINE],t[MAXLINE];

    printf("Enter A String:\n");
    getLine(s,MAXLINE);

    reverse(s);
    printf("\nEntered String in reverse is: %s\n",s);

    printf("\nEnter a String:\n");
    getLine(s,MAXLINE);

    printf("\nEnter another String:\n");
    getLine(t,MAXLINE);

    printf("\nEntered Strings are:\n 1. %s\n2. %s\n",s,t);

    printf("\nString t occurs at rightmost index %d of s\n",strindex(s,t));

    printf("\nEnter a Integer:\n");
    int n;

    scanf("%d",&n);

    printf("\nEntered Integer is %d\n",n);

    itoa(n,s);

    printf("\nInteger converted to string is: %s\n",s);

    return 0;
}

//reverse implemented with pointers

void reverse(char *s)
{
    int i=0;
    int temp,j=strlen(s)-1;

    for(i=0 ; i<j ; i++,j--)
    {
        temp  = *(s+i);

        *(s+i) = *(s+j);

        *(s+j) = temp;
    }

}

//itoa implemented with pointers

void itoa(unsigned int n, char *s) //issue fixed here changed type of n from int to unsigned int
{
    int i, sign;
    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    
    i = 0;

    do {
            /* generate digits in reverse order */
            *s++ = n % 10 + '0'; /* get next digit */
            i++;

    } while ((n /= 10) > 0);

    /* delete it */

    if (sign < 0)
    {
        *s++ = '-';
        i++;
    }
    
    *s = '\0';

    s -= i;
    
    reverse(s);
}

//strindex implemented with pointers

int strindex(char *s, char *t)
{
    int last_index_found=0;
    
    int len_t=strlen(t);
    
    for(int i=0 ; *s!='\0' ; s++,i++)
    {
        char *search_dummy_haystack= s; //intilalizing a dummy pointer to hold address pointed by s in 
        char *search_dummy_needle= t;   //every iteration to perform search operation without tinkering 
                                        //with address of s for current iteration
        int k=0;

        //here parameter for needle string search stop is \n because
        //getLine function stuffs any string with \n + \0 if carriage return was pressed
        //and thus to remove the effect of \n to get actual string we subtract 1 from len_T
        //and to make convention 0 index based another 1 is subtracted and hence logic len_T-2

        while( *search_dummy_needle!='\n' && *search_dummy_haystack == *search_dummy_needle )
        {
           if(k==len_t-2)
           {
              last_index_found=i;
           }
          k++;
          search_dummy_needle++;
          search_dummy_haystack++;           

        }

        //note the above defined logic is written keeping in mind that search is in a single line entered
        //in terminal for multiline string this can vary slightly 


    }

    if(!last_index_found)
        return -1;
    
    return last_index_found;

}


//getline implemented with pointers

void getLine(char *s, int lim)
{
    int c, i;
    
    i = 0;
    
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;

    if(c=='\n')
        *s++ = c;
    
    *s  = '\0';
    
}

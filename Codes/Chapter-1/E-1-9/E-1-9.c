//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
//more blanks by a single blank.

#include<stdio.h>
void main()
{
    int c,previous_char=0; //variable to i/p character stream from keyboard
    
    printf("Enter a Stream of Text:\n");
    
    while((c=getchar())!=EOF)
    {
        if(!((c==' ') && (previous_char==' '))) //put char iff c and previous_char are not blanks
        {
            putchar(c);
        }

        previous_char=c; //before reiterating the loop update current character to previous
    }
    
    printf("\nEOF Encountered Terminating I/P and Program Now\n");

}

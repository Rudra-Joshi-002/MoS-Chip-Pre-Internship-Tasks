/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include<stdio.h>
#include<math.h>

int invert(int ,int, int);

int main()
{
    int x,p,n;

    printf("\nEnter a Number:\n");
    scanf("%d",&x);
    
    printf("\nBit Position to Begin WIth:\n");
    scanf("%d",&p);

    printf("\nNumber of Bit from Positions on which to do the job\n");
    scanf("%d",&n);

    printf("\nEntered Numbers are as follows x: %d, p: %d, and n:%d\n",x,p,n);

    x=invert(x,p,n);

    printf("\nx after calling Invert is x: %d\n",x);   

    return 0;
}

//implementing the invert function
int invert(int x,int p,int n)
{
    if(x!=0)
    {
        int shifts=p-n+1;
        int mask=(int)((pow(2,n)-1));

        mask=mask<<shifts;

        return (x^mask);

    }
    else
        return x;

}

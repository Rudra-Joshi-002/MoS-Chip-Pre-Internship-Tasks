/*
Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include<stdio.h>
#include<math.h>

int setbits(int, int, int, int);

int main()
{
    int x,y,n,p;

    printf("Enter a number:\n");
    scanf("%d",&x);

    printf("\nEnter another number:\n");
    scanf("%d",&y);

    printf("\nEnter the amount of number of bits in another number that you want to insert into the 1st entered number:\n");
    scanf("%d",&n);

    printf("\nEnter the bit position of 1st number where you'd like to insert n-bits of another entered number:\n");
    scanf("%d",&p);

    printf("\nEntered Numbers are x: %d, y: %d, n: %d, p: %d\n",x,y,n,p);

    x=setbits(x,p,n,y);

    printf("\nAfter calling setbits the answer is: %d\n",x);

    return 0;

}

int setbits(int x, int p, int n, int y)
{
    int mask=(int)(pow(2,n)-1); //set the maskbits as per n
    
    int y_mask=y&mask; //mask the right most n-bits of y

    int shift=p-n+1; //variable to hold position at which masked bits of y are to be placed

    mask=mask<<shift; //to set ones to where the bits are to be place in x

    y_mask<<=shift; //to set the bits of y to as per where they are to be placed in x

    x&=~(mask); //clear the bits of x where n bits of y are to be placed

    return (x|y_mask);    

}

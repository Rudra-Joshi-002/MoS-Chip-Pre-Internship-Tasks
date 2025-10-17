/*
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the unsigned short integer x rotated
to the right by n positions.
*/

//note unsigned int is 2 bytes long so results will be according to 16 bit rotations

#include<stdio.h>

unsigned short int rightrot(unsigned short int ,unsigned short int);

int main()
{
    unsigned short int x,n;

    printf("\nEnter a Number:\n");
    scanf("%hd",&x);
    
    printf("\nEnter the amount by which you want to right rotate:\n");
    scanf("%hd",&n);

    printf("\nEntered Numbers are as follows x: %u, and n:%u\n",x,n);

    x=rightrot(x,n);

    printf("\nx after right rotating by entered amount is x: %u\n",x);

    return 0;
}

//impelementing rightrot here

unsigned short int rightrot(unsigned short int x,unsigned short int n)
{
    //makes a mask of 1 with number of bits being rotated n
    unsigned short int mask=(1<<n)-1;
    
    //save the bits that will be right rotated before actually rotating them
    unsigned short int image=x&mask;

    //now left shift the image by the amount (bitwidth [of type used] -n)
    image= image<<((sizeof(unsigned short int)*8)-n);

    //now right shift the number by required amount

    x=x>>n;

    //now place the image in upper bits of x

    return (x|image);

}

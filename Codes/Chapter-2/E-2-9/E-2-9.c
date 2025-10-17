/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/

//Reason for Expalin Part this is because in 2's complement number system the consecutive numbers
//differ fundamentally by the value of their least significant bit as an example consider the following
//
//0->000
//1->001
//2->010
//3->011
//4->100
//5->101
//6->110
//7->111
//here we can see that between any two consective numbers lsb toggles
//and hence when two consecutive numbers are ANDed then their lsb will be zero since it will alway produce 
//condition of either 0&1 or 1&0

#include<stdio.h>

unsigned int bitcount(unsigned int);

int main()
{
    unsigned int x,count;
    
    printf("Enter a Number:\n");
    scanf("%u",&x);

    count=bitcount(x);

    printf("\nNumber of 1's in %u is %u\n",x,count);

    return 0;
}

unsigned int bitcount(unsigned int x)
{
    unsigned int i=0;
    //to understand its beauty take calculator and do it for a example and you'll see
    while(x!=0)
    {
        x&=(x-1);
        i++;
    }

    return i;

}


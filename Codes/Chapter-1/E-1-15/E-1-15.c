#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 25

float degree_2_fahr(float deg);

int main()
{
    printf("Printing a Degree to Fahrenhiet Conversion Table:\n"); 

    for(int i=LOWER;i<=UPPER;i=i+STEP)
    {
        printf("Degree: %f | Fahrenhiet: %f\n",(float)i,degree_2_fahr(i));  
    }

    return 0;
}

float degree_2_fahr(float deg)
{
    return (float) (((float)(9/5)*deg)+32);
}


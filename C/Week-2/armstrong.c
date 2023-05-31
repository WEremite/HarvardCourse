#include <stdio.h>
#include <math.h>

int main(void)
{
    int candidate = 153;
    int num1 = candidate;
    int num2 = candidate;
    int power = 0;
    int sum = 0;
    
    while (num1 > 0)
    {
        num1 /= 10;
        power += 1;
    }
    
    while (num2 > 0)
    {
        sum += pow((num2 % 10), power);
        num2 /= 10;
    }
    
    if (candidate == sum)
    {
        printf("It's an Armstrong number\n");
    }
    else
    {
        printf("It's not an Armstrong number\n");
    }
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("Type number for x: ");
    int y = get_int("Type number for y: ");

    if (x > y)
    {
        printf("x is greater than y\n");
    }
    else if (x < y)
    {
        printf("x is lesser than y\n");
    }
    else
    {
        printf("x and y are equal\n");
    }
    
}
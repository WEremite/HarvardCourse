#include <cs50.h>
#include <stdio.h>

int get_levels(void);
void build_pyramid(int level, char hashtag);

int main(void)
{
    // Get height of pyramid
    int pyramid_height = get_levels();
    char hashtag = '#';

    build_pyramid(pyramid_height, hashtag);
}

// Getting height of pyramid from user
int get_levels(void)
{
    int height;
    do
    {
        height = get_int("Type pyramid height (1-8): ");
    }
    while (height > 8 || height < 1);

    return height;
}

// Main logic - building pyramid
void build_pyramid(int level, char hashtag)
{
    for (int i = 1; i <= level; i++)
    {
        // Build left pyramid
        // Add spaces before hashtag in left pyramid
        int spaces = level - i;
        printf("%*s", spaces, "");

        int step1 = i;
        while (step1 > 0)
        {
            printf("%c", hashtag);
            step1--;
        }

        // Add gap
        printf("%*s", 2, "");

        // Build right pyramid
        int step2 = i;
        while (step2 > 0)
        {
            printf("%c", hashtag);
            step2--;
        }
        printf("\n");
    }
}
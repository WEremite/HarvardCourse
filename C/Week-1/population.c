#include <cs50.h>
#include <stdio.h>

#define BORN 3
#define PASSED 4

int start_size(void);
int end_size(int start_size);
int num_year(int start_size, int end_size);

int main(void)
{
    // TODO: Prompt for start size
    int start = start_size();
    // TODO: Prompt for end size
    int end = end_size(start);
    // TODO: Calculate number of years until we reach threshold
    int years = num_year(start, end);
    // TODO: Print number of years
    printf("Years: %d\n", years);
}

// Getting start size of population
int start_size(void)
{
    int start;
    do
    {
        start = get_int("Enter start population of llamas: ");
    }
    while (start < 9);

    return start;
}

// Getting end size of population
int end_size(int start_size)
{
    int end;
    do
    {
        end = get_int("Enter end population of llamas: ");
    }
    while (end < start_size);

    return end;
}

// Main logic. Counting years
int num_year(int start_size, int end_size)
{
    int year = 0;
    int population = start_size;

    while (population < end_size)
    {
        int increase = population / BORN;
        int decrease = population / PASSED;
        population += increase - decrease;
        year++;
    }

    return year;
}
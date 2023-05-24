#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Function to calculate total or average hours
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Get the number of weeks taking CS50
    int weeks = get_int("Number of weeks taking CS50: ");

    // Create an array to store the hours for each week
    int hours[weeks];

    // Prompt the user to enter the number of hours for each week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Prompt the user to choose between total or average hours
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Calculate and print the result using the calc_hours function
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Function to calculate total or average hours
float calc_hours(int hours[], int weeks, char output)
{
    float total_hours = 0;

    // Calculate the total number of hours
    for (int i = 0; i < weeks; i++)
    {
        total_hours += hours[i];
    }

    // Return the result based on the user's choice
    if (output == 'T')
    {
        return total_hours; // Return the total hours
    }
    else
    {
        return total_hours / weeks; // Return the average hours per week
    }
}
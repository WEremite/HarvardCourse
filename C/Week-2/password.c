// Check that a password has at least one lowercase letter, uppercase letter, number, and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a password is valid
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: "); // Get the password from the user

    if (valid(password)) // Check if the password is valid
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Function to check the validity of a password
bool valid(string password)
{
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < strlen(password); i++) // Iterate through each character of the password
    {
        if (islower(password[i])) // Check if the character is a lowercase letter
        {
            lower = true;
        }
        else if (isupper(password[i])) // Check if the character is an uppercase letter
        {
            upper = true;
        }
        else if (isdigit(password[i])) // Check if the character is a digit
        {
            number = true;
        }
        else if (ispunct(password[i])) // Check if the character is a symbol
        {
            symbol = true;
        }

        if (upper && lower && number && symbol) // If all required conditions are met, return true
        {
            return true;
        }
    }

    return false; // If any of the required conditions are not met, return false
}

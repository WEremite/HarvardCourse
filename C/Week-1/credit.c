#include <cs50.h>
#include <stdio.h>

int count_digits(long card_num);
int get_second_to_last_sum(long card_num);
int get_other_nums_sum(long card_num);
int get_first_two_nums(long card_num);
const char* check_validity(long card_num);

int main(void)
{
    // Get user input of card number
    long card_num = get_long("Write card number, please: ");

    const char* result = check_validity(card_num);

    printf("%s", result);
}

// Counting digits on the card
int count_digits(long card_num)
{
    long temp = card_num;
    int count = 0;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }

    return count;
}

// First step of the Luhn's algorithm
int get_second_to_last_sum(long card_num)
{
    int result = 0;
    long temp = card_num;
    int temp2;
    // picking every second number from end of digits
    while (temp > 10)
    {
        temp /= 10;
        temp2 = temp % 10 * 2;
        if (temp2 >= 10)
        {
            result += temp2 / 10 + temp2 % 10;
        }
        else
        {
            result += temp2;
        }
        temp /= 10;
    }
    return result;
}

// Second step of the Luhn's algorithm
int get_other_nums_sum(long card_num)
{
    int result = 0;
    long temp = card_num;
    int temp2;

    while (temp > 0)
    {
        temp2 = temp % 10;
        result += temp2;

        temp /= 100;
    }
    return result;
}

// Get first two numbers for checking type of card
int get_first_two_nums(long card_num)
{
    long temp = card_num;

    while (temp > 100)
    {
        temp /= 10;
    }

    return temp;
}

// Main logic
const char* check_validity(long card_num)
{
    int count = count_digits(card_num);

    if (count < 13 || count > 16) // Check valid quantity of digits
    {
        return "INVALID\n";
    }

    int luhns_algorithm = (get_second_to_last_sum(card_num) + get_other_nums_sum(card_num)) % 10;
    
    if (luhns_algorithm != 0) // Check by Luhn's algorithms
    {
        return "INVALID\n";
    }

    int first_two_nums = get_first_two_nums(card_num);

    if (first_two_nums == 34 || first_two_nums == 37) // Check for AMEX
    {
        return "AMEX\n";
    }
    else if (first_two_nums > 39 && first_two_nums < 50) // Check for VISA
    {
        return "VISA\n";
    }
    else if (first_two_nums > 50 && first_two_nums < 56) // Check for MASTERCARD
    {
        return "MASTERCARD\n";
    }

    return "INVALID\n";

}
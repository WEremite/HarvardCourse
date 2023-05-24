// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string user_word);

// vowels to numbers: a becomes 6, e becomes 3, i becomes 1, o becomes 0
char A = '6';
char E = '3';
char I = '1';
char O = '0';

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    printf("%s\n", replace(argv[1]));

}

string replace(string user_word)
{
    // find and replace letters
    for (int i = 0; i < strlen(user_word); i++)
    {
        if (user_word[i] == 'a')
        {
            user_word[i] = A;
        }
        else if (user_word[i] == 'e')
        {
            user_word[i] = E;
        }
        else if (user_word[i] == 'i')
        {
            user_word[i] = I;
        }
        else if (user_word[i] == 'o')
        {
            user_word[i] = O;
        }
    }

    return user_word;
}
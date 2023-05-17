#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int UPPERCODE = 65;
int LOWERCODE = 97;

int compute_score(string word);
int get_points(int letter, int code);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: "); // Get word input from Player 1
    string word2 = get_string("Player 2: "); // Get word input from Player 2

    // Score both words
    int score1 = compute_score(word1); // Calculate the score for word1
    int score2 = compute_score(word2); // Calculate the score for word2

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (islower(word[i]))
        {
            score += get_points(word[i], LOWERCODE); // Calculate the score for lowercase letter
        }
        else if (isupper(word[i]))
        {
            score += get_points(word[i], UPPERCODE); // Calculate the score for uppercase letter
        }

    }
    return score;
}

int get_points(int letter, int code)
{
    return POINTS[letter - code]; // Get the score associated with the letter
}
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function declarations
int count_letters(string text, int text_length);
int count_words(string text, int text_length);
int count_sentences(string text, int text_length);

// Coefficients for the Coleman-Liau index calculation
float COEFFICIENT_1 = 0.0588;
float COEFFICIENT_2 = 0.296;
float COEFFICIENT_3 = 15.8;

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Calculate the length of the text
    int length = strlen(text);

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text, length);
    int words = count_words(text, length);
    int sentences = count_sentences(text, length);

    // Calculate the average number of letters and sentences per 100 words
    float l = (float) letters / (float) words * 100;
    float s = (float) sentences / (float) words * 100;

    // Calculate the Coleman-Liau index
    int index = round((COEFFICIENT_1 * l) - (COEFFICIENT_2 * s) - COEFFICIENT_3);

    // Determine the grade level based on the index and print the result
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Function to count the number of letters in the text
int count_letters(string text, int text_length)
{
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i])) // Check if the character is alphabetical
        {
            count++;
        }
    }
    return count;
}

// Function to count the number of words in the text
int count_words(string text, int text_length)
{
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i])) // Count words by whitespaces
        {
            count++;
        }
    }
    count++; // Add the last word
    return count;
}

// Function to count the number of sentences in the text
int count_sentences(string text, int text_length)
{
    int count = 0;
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // Count sentences by punctuation
        {
            count++;
        }
    }
    return count;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char* word = "six-year-old";
  int word_length = strlen(word);
  int count = 0;
  
  for (int i = 0; i < word_length - 1; i++)
  {
    for (int j = i + 1; j < word_length; j++)
    {
      printf("%c %c\n", word[i], word[j]);
      if (isalpha(word[i]))
      {
        if (word[i] == word[j])
        {
            count += 1;
        }
      }

    }
  }
  
  printf("%i\n", count);
  
}
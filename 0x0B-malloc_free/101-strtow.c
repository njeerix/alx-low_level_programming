#include "main.h"
#include <stdlib.h>
/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
int count = 0;
int in_word = 0;
while (*str)
{
if (*str == ' ')
in_word = 0;
else if (in_word == 0)
{
in_word = 1;
count++;
}
str++;
}
return (count);
}
/**
 * strtow - Splits a string into words
 * @str: The input string.
 * Return: Pointer to an array of strings (words).
 */
char **strtow(char *str)
{
char **words = NULL;
int word_count, i;
int word_length, j;
if (str == NULL || *str == '\0')
return (NULL);
word_count = count_words(str);
if (word_count == 0)
return (NULL);
for (i = 0; i < word_count; i++)
{
while (*str == ' ')
str++;
word_length = 0;
while (str[word_length] && str[word_length] != ' ')
word_length++;
words[i] = malloc((word_length + 1) * sizeof(char));
if (words[i] == NULL)
{
while (i > 0)
free(words[--i]);
free(words);
return (NULL);
}
for (j = 0; j < word_length; j++)
{
words[i][j] = str[j];
}
words[i][word_length] = '\0';
str += word_length;
}
return (words);
}

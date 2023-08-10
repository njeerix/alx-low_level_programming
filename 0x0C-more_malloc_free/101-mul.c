#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
int i = 0;
while (s[i] != '\0')
{
i++;
}
return (i);
}
/**
 * is_valid_number - checks if a string contains only digits
 * @s: string to be evaluated
 * Return: 1 if valid, 0 otherwise
 */
int is_valid_number(char *s)
{
while (*s)
{
if (*s < '0' || *s > '9')
return (0);
s++;
}
return (1);
}
/**
 * multiply_strings - multiplies two strings representing numbers
 * @s1: first number string
 * @s2: second number string
 */
void multiply_strings(char *s1, char *s2)
{
int len1, len2, len, i, carry, digit1, digit2;
int start = 0;
int *result;
len1 = _strlen(s1);
len2 = _strlen(s2);
len = len1 + len2 + 1;
result = malloc(sizeof(int) * len);
if (!result)
return;
for (i = 0; i < len; i++)
result[i] = 0;
for (len1 = len1 - 1; len1 >= 0; len1--)
{
digit1 = s1[len1] - '0';
carry = 0;
for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
{
digit2 = s2[len2] - '0';
carry += result[len1 + len2 + 1] + (digit1 *digit2);
result[len1 + len2 + 1] = carry % 10;
carry /= 10;
}
if (carry > 0)
result[len1 + len2 + 1] += carry;
}
while (start < len - 1 && result[start] == 0)
start++;
if (start == len - 1)
putchar('0');
else
{
for (i = start; i < len; i++)
putchar(result[i] + '0');
}
putchar('\n');
free(result);
}
/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of pointers to the arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
{
puts("Error");
return (1);
}
multiply_strings(argv[1], argv[2]);
return (0);
}

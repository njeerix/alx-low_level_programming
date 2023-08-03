#include "main.h"
/**
 * _strlen_recursion - returns the length of a string
 * @s: string to calculate the length
 * Return: length of the string
 */
int _strlen_recursion(char *s)
{
if (*s == 0)
return (0);
else
return (1 + _strlen_recursion(s + 1));
}
/**
 * _chunk_ispal - Tests if a part of a string is palindrome
 * @s: string
 * @start: start
 * @end: end
 * Return: 1 if palindrome, 0 if not
 */
int _chunk_ispal(char *s, int start, int end)
{
if (start == end)
return (1);
if (s[start] != s[end])
return (0);
if (start < end + 1)
return (_chunk_ispal(s, start + 1, end - 1));
return (0);
}
/**
 * is_palindrome - Tests if a string is a palindrome.
 * @s: The string to test.
 * Return: 1 if s is a palindrome 0 if not
 */
int is_palindrome(char *s)
{
int n = _strlen_recursion(s);
if (n == 0)
return (1);
return (_chunk_ispal(s, 0, n - 1));
}

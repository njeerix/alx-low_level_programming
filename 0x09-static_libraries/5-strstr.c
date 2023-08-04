#include "main.h"
#include <stddef.h>
/**
 * _strstr - function that locates a substring
 * @haystack: string to be searched
 * @needle: substring to be located
 * Return: A pointer to the beginning located substring, else NULL
 */
char *_strstr(char *haystack, char *needle)
{
int i, j;
if (*needle == '\0')
return (haystack);
for (i = 0; haystack[i] != '\0'; i++)
{
for (j = 0; haystack[i + j] == needle[j]; j++)
{
if (needle[j + 1] == '\0')
return (haystack + i);
}
}
return (NULL);
}

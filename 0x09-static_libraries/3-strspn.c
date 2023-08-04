#include "main.h"
/**
 * _strspn - length of a prefix substring
 * @s: string to be searched
 * @accept: prefix to be measured
 * Return: number of bytes in s
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
while (*s && *accept && *s == *accept)
{
s++;
accept++;
count++;
}
return (count);
}

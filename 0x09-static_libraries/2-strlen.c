#include "main.h"
/**
 * _strlen - return length of string
 * @s: string
 * Return: length of sting
 */
int _strlen(char *s)
{
int len = 0;
while (*s != '\0')
{
len++;
s++;
}
return (len);
}

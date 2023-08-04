#include "main.h"
/**
 * _strcat - concatenate two strings
 * @dest: The destination string
 * @src: The source string
 * Return: pointer to string
 */
char *_strcat(char *dest, char *src)
{
int i = 0, n = 0;
while (dest[n] != '\0')
n++;
while (src[i] != '\0')
{
dest[n + i] = src[i];
i++;
}
dest[n + i] = '\0';
return (dest);
}

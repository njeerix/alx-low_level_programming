#include "main.h"
#include <stdlib.h>
/**
 * argstostr - Concatenates all the arguments of the program
 * @ac: The argument count
 * @av: The argument vector
 * Return: If successful, returns a pointer to the concatenated string.
 *         Returns Null on failure or if ac == 0 ar av == NULL.
 */
char *argstostr(int ac, char **av)
{
int total_length = 0;
char *str;
int i, j, index = 0;
if (ac == 0 || av == NULL)
return (NULL);
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j] != '\0'; j++)
total_length++;
total_length++;
}
str = (char *)malloc(total_length + 1);
if (str == NULL)
return (NULL);
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
str[index++] = av[i][j];
str[index++] = '\n';
}
str[index] = '\0';
return (str);
}

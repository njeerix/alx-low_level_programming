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
int arg_length = 0;
int total_length = 0;
char *concatenated;
int position = 0;
int i;
if (ac == 0 || av == NULL)
return (NULL);
for (i = 0; i < ac; i++)
{
while (av[i][arg_length] != '\0')
arg_length++;
total_length += arg_length + 1;
}
concatenated = (char *)malloc((total_length + 1) * sizeof(char));
if (concatenated == NULL)
return (NULL);
for (i = 0; i < ac; i++)
{
while (av[i][arg_length] != '\0')
{
concatenated[position] = av[i][arg_length];
position++;
arg_length++;
}
concatenated[position] = '\n';
position++;
}
concatenated[position] = '\0';
return (concatenated);
}

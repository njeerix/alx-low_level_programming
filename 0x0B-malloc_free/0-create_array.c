#include "main.h"
#include <stdlib.h>
/**
 * create_array - Creates and initializes an array of chars
 * @size: The size of the array
 * @c: The character to initialize the array with
 * Return: If successful, returns a pointer to the created array.
 *         If size is 0 or memory allocation fails, returns NULL.
 */
char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;
if (size == 0)
return (NULL);
array = (char *)malloc(size * sizeof(char));
if (array == NULL)
return (NULL);
for (i = 0; i < size; i++)
{
array[i] = c;
}
return (array);
}

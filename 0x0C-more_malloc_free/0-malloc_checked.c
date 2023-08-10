#include "main.h"
#include <stdlib.h>
/**
 * malloc_checked - Allocates memory using malloc.
 * @b: Size of memory to allocate.
 *
 * Return: Pointer to the allocated memory.
 *         Exits with status value 98 if malloc fails.
 */
void *malloc_checked(unsigned int b)
{
void *ptr = malloc(b);
if (ptr == NULL)
exit(98);
return (ptr);
}

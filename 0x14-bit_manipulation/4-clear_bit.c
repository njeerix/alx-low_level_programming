#include "main.h"
#include <stddef.h>
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to the unsigned long integer
 * @index: index of the bit to clear
 * Return: 1 if it worked, or -1 if an error occured.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;
if (n == NULL || index >= sizeof(unsigned long int) * 8)
return (-1);
mask <<= index;
mask = -mask;
*n &= mask;
return (1);
}

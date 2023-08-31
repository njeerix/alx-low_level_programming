#include "main.h"
/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long integer.
 * Return: 1 if it worked, or -1 if an error occured.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;
if (index >= sizeof(unsigned long int) * 8)
return (-1);
mask <<= index;
*n |= mask;
return (1);
}

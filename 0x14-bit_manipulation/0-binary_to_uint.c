#include "main.h"
/**
 * binary_to_unit - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 * Return: The converted number, or 0 if there's an invalid char in the string.
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;
unsigned int power = 1;
if (b == NULL)
return (0);
while (b && *b)
b++;
while (--b)
{
if (*b != '0' && *b != '1')
return (0);
if (*b == '1')
result += power;
power *= 2;
}
return (result);
}

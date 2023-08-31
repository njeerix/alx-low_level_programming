#include "main.h"
/**
 * beinary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to a string of 0 and 1 chars.
 * Return: The converted number, or 0 if there's an invalid
 * char in the string.
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;
unsigned int power = 1;
int i;
if (!b)
return (0);
for (i = 0; b[i] != '\0'; i++)
{
if (b[i] != '0' && b[i] != '1')
return (0);
}
for (i = i - 1; i >= 0; i--)
{
if (b[i] == '1')
result += power;
power *= 2;
}
return (result);
}

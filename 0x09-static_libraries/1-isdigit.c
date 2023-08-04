#include "main.h"
/**
 * _isdigit - checks if parameter is a digit between 0 and 9
 * @c: input number
 * Return: 1 if true, 0 if not
 */
int _isdigit(int c)
{
if (c >= '0' && c <= '9')
return (1);
else
return (0);
}

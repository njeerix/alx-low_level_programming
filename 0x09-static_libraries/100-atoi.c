#include "main.h"
/**
 * _atoi - converts string to an integer
 * @s: the string to be converted
 * Return: integer value of the converted string
 */
int _atoi(char *s)
{
int sign = 1;
int result = 0;
int i = 0;
if (s[0] == '-')
{
sign = -1;
i++;
}
while (s[i] != '\0')
{
if (s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
}
else
{
break;
}
i++;
}
return (result *sign);
}

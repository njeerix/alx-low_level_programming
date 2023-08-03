#include "main.h"
/**
 * wildcmp - compare strings
 * @s1: first string
 * @s2: second string
 * Return: 1 if the strings will be considered, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '*')
{
if (*(s2 + 1) == '*')
return (wildcmp(s1, s2 + 1));
else if (wildcmp(s1, s2 + 1))
return (1);
else
return (wildcmp(s1 + 1, s2));
}
else if (*s2 == '\0')
{
if(*s1 == '\0')
return (1);
else
return (0);
}
else if (*s1 == *s2)
return (wildcmp(s1 + 1, s2 + 1));
else
return (0);
}

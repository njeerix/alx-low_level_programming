#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string params
 * @s2: second string params
 *
 * Return:
 * returns 0 if s1 == s2
 * returns negative number if s1 < s2
 * returns positive number if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}
return (*s1 - *s2);
}

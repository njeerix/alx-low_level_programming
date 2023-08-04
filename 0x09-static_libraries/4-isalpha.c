#include "main.h"
/**
 * _isalpha - shows 1 if input is an alphabet
 * @c: character to check
 * Return: 1 for the alphabet 0 for the rest
 */
int _isalpha(int c)
{
return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

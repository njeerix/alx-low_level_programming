#include "main.h"
/**
 * _find_sqrt - finds the square root of a number using binary search.
 * @n: the number whose the square root will be found
 * @low: the lower bound for the binary search.
 * @high: The upper bound for the binary search.
 * Return: The square root of n if it exists, -1 otherwise.
 */
int _find_sqrt(int n, int low, int high)
{
long sqr;
int mid;
if (low <= high)
{
mid = low + (high - low) / 2;
sqr = (long)mid * mid;
if (sqr == n)
return (mid);
else if (sqr < n)
return (_find_sqrt(n, mid + 1, high));
else
return (_find_sqrt(n, low, mid - 1));
}
return (-1);
}
/**
 * _sqrt_recursion - rturns the natural square root of a number.
 * @n: The number whose the square root will be returned.
 * Return: The square root of n.
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (_find_sqrt(n, 0, n));
}

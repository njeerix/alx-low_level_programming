#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_all - Print values of different types.
 * @format: The format string indicating types of arguments.
 * @...: The variable number of arguments.
 */
void print_all(const char * const format, ...)
{
va_list args;
int i = 0;
char *str;
char c;
va_start(args, format);
while (format && format[i])
{
switch (format[i])
{
case 'c':
c = va_arg(args, int);
printf("%c", c);
break;
case 'i':
printf("%d", va_arg(args, int));
break;
case 'f':
printf("%f", va_arg(args, double));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(nil)";
printf("%s", str);
break;
default:
break;
}
if (format[i + 1] != '\0' && (format[i] == 'c' || format[i] == 'i' || format[i] == 'f' || format[i] == 's'))
printf(", ");
i++;
}
va_end(args);
printf("\n");
}

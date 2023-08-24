#include <stdio.h>
void myStartupFun(void) __attribute__ ((constructor));
/**
 * myStartupFun - Prints the required lines before main is executed.
 */
void myStartupFun(void)
{
printf("You're beat! and yet, you must allow, \nI bore my house upon my back!\n");
}

#include "dog.h"
#include <stdio.h>
/**
 * print_dog - Prints the details of a dog.
 * @d: Pointer to the struct dog variable to be printed.
 */
void print_dog(struct dog *d)
{
if (d != NULL)
{
printf("Name: %s\n", d->name ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
}

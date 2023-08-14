#include "dog.h"
#include <stddef.h>
/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: Pointer to the struct dog variable to be initialized.
 * @name: Pointer to the name value.
 * @age: Float value for the age.
 * @owner: Pointer to the owner value.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d != NULL)
{
d->name = name;
d->age = age;
d->owner = owner;
}
}

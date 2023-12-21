#include <stdlib.h>
#include "hash_tables.h"
/**
 * hash_table_create - Createss a hash table
 * @size: Size of the array for the hash table
 * Return: A pointer to the newly created hash table, or NULL if failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
unsigned long int i;
hash_table_t *new_table;
if (size == 0)
return NULL;
new_table = malloc(sizeof(hash_table_t));
if (new_table == NULL)
return NULL;
new_table->array = malloc(sizeof(hash_node_t *) * size);
if (new_table->array == NULL)
{
free(new_table);
return NULL;
}
for (i = 0; i < size; i++)
{
new_table->array[i] = NULL;
}
new_table->size = size;
return new_table;
}

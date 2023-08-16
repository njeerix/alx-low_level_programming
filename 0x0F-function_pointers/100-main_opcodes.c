#include <stdio.h>
#include <stdlib.h>
/**
 * main - Prints the opcodes of its own main function
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 * Return: 0 on success, 1 if argument count is not correct, 2 if num_bytes
 */
int main(int argc, char **argv)
{
if (argc != 2)
{
printf("Error\n");
return (1);
}
int num_bytes = atoi(argv[1]);
if (num_bytes <= 0)
{
printf("Error\n");
return (2);
}
char *main_ptr = (char *)main;
int i;
for (i = 0; i <num_bytes; i++)
{
printf("%02x", (unsigned char)main_ptr[i]);
if (i < num_bytes - 1)
printf(" ");
i++;
}
printf("\n");
return (0);
}

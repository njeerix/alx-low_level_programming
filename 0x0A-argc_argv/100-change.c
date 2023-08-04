#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entyr point
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
int coins[] = {25, 10, 5, 2, 1};
int cents, num_coins = 0;
int i;
int num_coin_types = sizeof(coins) / sizeof(coins[0]);
if (argc != 2)
{
printf("Error\n");
return (1);
}
cents = atoi(argv[1]);
if (cents < 0)
{
printf("0\n");
return (0);
}
for (i = 0; i < num_coin_types; i++)
{
while (cents >= coins[i])
{
cents -= coins[i];
num_coins++;
}
}
printf("%d\n", num_coins);
return (0);
}

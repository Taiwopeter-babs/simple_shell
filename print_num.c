#include "main.h"
/**
 * print_num - prints positive numbers i.e unsigned
 * @num: number parameter
 * Return: length of number printed
 */
int print_num(int num)
{
	unsigned int n;
	int div, len;

	n = num;
	div = 1;

	while (n / div >= 10)
		div *= 10;

	len = 0;
	while (div > 0)
	{
		len += _putchar((num / div) + '0');
		num %= div;
		div /= 10;
	}

	return (len);
}

#include "main.h"
/**
 * _putchar - writes character to stdout
 * @c: character to be printed
 * Return: number of bytes written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string to stdout
 * @str: string parameter
 * @new_line: if integer is 1, new line will be printed, if 0 newline
 * will not be printed to stdout
 * Return: nothing
 */
void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
	if (new_line == 1)
		write(STDOUT_FILENO, "\n", 1);
}
/**
 * print_error - prints error message to stdout
 * @av: name of program running shell
 * @command: command not found to be printed
 * Return: nothing
 */
void print_error(char *av, char *command)
{
	print_str(av, 0);
	print_str(": ", 0);
	print_num(STDOUT_FILENO);
	print_str(": ", 0);
	print_str(command, 0);
	/* print_str(": not found", 1); */
}

#include "main.h"
/**
 * main - entry point to program
 * @ac: number of command line arguments
 * @av: pointer to strings of command line arguments
 * Return: 0 on success
 */
int main(int __attribute__((unused)) ac, char **av)
{
	int cmd_count;
	char *lineptr;
	size_t bufsize;

	cmd_count = 0;
	do {
		cmd_count++;
		bufsize = 0;
		lineptr = NULL;
		exec_command(av, lineptr, bufsize, cmd_count);
	} while (1);

	return (0);
}

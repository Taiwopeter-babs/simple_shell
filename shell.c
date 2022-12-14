#include "main.h"
/**
 * main - entry point to program
 * @ac: number of command line arguments
 * @av: pointer to strings of command line arguments
 * Return: 0 on success
 */
int main(int __attribute__((unused)) ac, char **av)
{
	char *lineptr;
	size_t bufsize;

	do {
		bufsize = 0;
		lineptr = NULL;
		exec_command(av, lineptr, bufsize);
	} while (1);

	return (0);
}

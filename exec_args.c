#include "main.h"
/**
 * create_child - creates a child to execute the program
 * @args: array of strings that contain the command and arguments
 * @lineptr: pointer to line that was read
 * @av: Name of program running the shell
 * Return: nothing
 */
void create_child(char **args, char *lineptr, char **av)
{
	pid_t pid;
	struct stat statbuf;
	int check, i;
	int status;
	char *temp_command;

	pid = fork();

	if (pid == 0)
	{
		temp_command = args[0];

		check = stat(temp_command, &statbuf);
		if (check == -1)
		{
			print_error(av[0], temp_command);
			print_str(": not found", 1);
			free_at_once(1, lineptr);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);

			exit(100);
		}

		if (temp_command != NULL)
		{
			if (execve(temp_command, args, environ) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
	}
	else
	{
		wait(&status);
	}

}

/**
 * exec_command - executes the whole program
 * @av: command line vector pointer
 * @lineptr: string that holds the user input. Set to NULL\n
 * and will be dynamically allocated memory by getline()
 * @bufsize: size of lineptr (set to 0, will be the size of memory allocated
 * by getline().
 * Return: nothing
 */
void exec_command(char **av, char *lineptr, size_t bufsize)
{
	char *delim = " \n\t";
	char **args;
	char *prompt = "#cisfun$ ";
	ssize_t nread;
	int i;



	write(STDOUT_FILENO, prompt, _strlen(prompt));
	nread = getline(&lineptr, &bufsize, stdin);
	if (nread != -1)
	{
		lineptr[nread - 1] = '\0';
		args = tokenize_input(lineptr, delim);
		if (args[0] == NULL)
		{
			free_at_once(2, args, lineptr);
			return;
		}
		i = exec_builtin(args, lineptr);
		if (i == -1)
			create_child(args, lineptr, av);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);

		free_at_once(2, args, lineptr);
	}
	else
		exit_built(lineptr);
}
/**
 * free_at_once - frees arguments that are strings
 * @n: number of arguments to free
 * Return: nothing
 */
void free_at_once(int n, ...)
{
	int i;
	va_list args;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char*);
		if (str == NULL)
			str = "(null)";
		free(str);
	}
	va_end(args);
}

#include "main.h"
/**
 * exit_built - exits the shell program
 * @lineptr: pointer to strings of arguments in shell
 * Return: nothing
 */
<<<<<<< HEAD
=======

>>>>>>> 22220f1b578f4724b09aebc5dac8d442176223b6
void exit_built(char *lineptr)
{
	free(lineptr);
	/* print_str("\n", 0); */
	exit(1);
}
/**
 * env_shell - prints the current enviroment of shell
 * @args: pointer to strings of arguments in shell
 * Return: nothing
 */
<<<<<<< HEAD
void env_shell(char _attribute_((unused)) *args)
=======
void env_shell(char __attribute__((unused)) *args)
>>>>>>> 22220f1b578f4724b09aebc5dac8d442176223b6
{
	size_t k, j;

	k = 0;
	while (environ[k] != NULL)
	{
		j = 0;
		while (environ[k][j] != '\0')
		{
			write(STDOUT_FILENO, &environ[k][j], 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}
/**
 * get_builtin - gets the appropriate builtin command
 * @args: command argument on shell
 * Return: pointer to corresponding function, otherwise NULL
 */
void (*get_builtin(char *args))(char *args)
{
	builtin_f builtin_func[] = {
			{"exit", exit_built},
			{"env", env_shell},
			{NULL, NULL}
	};
	int k;

	k = 0;
	while (builtin_func[k].cmd != NULL)
	{
		if (_strcmp(builtin_func[k].cmd, args) == 0)
			return (builtin_func[k].func);
		k++;
	}
	return (NULL);

}
/**
 * exec_builtin - executes the builtin function
 * @args: command arguments in shell
 * @lineptr: line input read from user
 * Return: -1 if builtin doesn't exist in struct,
 * otherwise, 0 on success
 */
int exec_builtin(char **args, char *lineptr)
{
	int i;
	void (*func)(char *);

	func = get_builtin(args[0]);
	if (func == NULL)
		return (-1);
	if (_strcmp(args[0], "exit") == 0)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}
	func(lineptr);
	return (0);
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if they are equal, otherwise a positive value
 * if s1 > s2, or negative value if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int k;
	int value;

	value = 0;
	for (k = 0; value == 0; k++)
	{
		if (s1[k] == '\0' && s2[k] == '\0')
			break;
		value += s1[k] - s2[k];

	}
	return (value);
}

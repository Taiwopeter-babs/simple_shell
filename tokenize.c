#include "main.h"
/**
 * count_token - count the number of tokens gotten
 * so memory can be allocated
 * @lineptr: pointer to string on the shell stdin
 * @delim: delimiters separating each token
 * Description: Duplicate the lineptr so you can work with it
 * Return: number of tokens, or -1 on error
 */
int count_token(char *lineptr, char *delim)
{
	char *str;
	char *token;
	int count;

	str = _strdup(lineptr);
	if (str == NULL)
		return (-1);

	token = strtok(str, delim);

	for (count = 0; token != NULL; count++)
	{
		token = strtok(NULL, delim);
	}
	free(str);
	return (count);
}


/**
 * tokenize_input - tokenize the input
 * @lineptr: pointer to string on shell stdout
 * @delim: delimiters separating the string tokens
 * Return: pointer to buffer storing the tokenized string
 */
char **tokenize_input(char *lineptr, char *delim)
{
	char **buffer;
	char *token;
	char *str;
	int i, token_count;

	token_count = count_token(lineptr, delim);

	buffer = malloc(sizeof(char *) * (token_count + 1));
	if (buffer == NULL)
		return (NULL);

	str = _strdup(lineptr);
	token = strtok(str, delim);

	i = 0;
	while (token != NULL)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	buffer[i] = NULL;

	free(str);
	/*free(lineptr);*/

	return (buffer);
}

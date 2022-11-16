#include "main.h"

/**
 * _strlen - computes length of string
 * @str: parameter string
 * Return: length calculated
 */
int _strlen(char *str)
{
	int len;

	if (str == NULL)
		return (-1);

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strdup - makes a copy of the source string to a new string
 * @src: source string to be duplicated
 * Return: pointer to duplicate
 */
char *_strdup(char *src)
{
	int i, len;
	char *dup_str;

	len = _strlen(src);
	dup_str = malloc(sizeof(char) * (len + 1));

	i = 0;
	while (src[i] != '\0')
	{
		dup_str[i] = src[i];

		i++;
	}
	dup_str[i] = '\0';

	return (dup_str);
}

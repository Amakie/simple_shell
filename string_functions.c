#include "shell.h"

/**
 * _putchar - ...
 * @c: ...
 *
 * Return: ...
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - ...
 * @str: ...
 *
 * Return: ...
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++
	}
	_putchar('\n');
}

/**
 * _strlen - ...
 * @str: ...
 *
 * Return: ...
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _atoi - ...
 * @str: ...
 *
 * Return: ...
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * _strdup - ...
 * @str: ...
 *
 * Return: ...
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	if (str != NULL)
		dup = (char *)malloc((sizeof(char) * len) + 1);

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';

	return (dup);
}

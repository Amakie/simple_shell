#include "shell.h"

/**
 * _setenv - Sets value of an environment variable
 * @args: Arguments
 * Return: Nothing
 */
int _setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		_printerror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		_puts("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @args: Arguments
 * Return: Nothing
 */
int _unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		_printerror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		_puts("unsetenv");
	}
	return (0);
}

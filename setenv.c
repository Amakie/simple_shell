#include "shell.h"

/**
 * _setenv - Sets value of an environment variable
 * @args: Arguments 
 * Return: 0
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
		_printerror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @args: Arguments 
 * Return: 0
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
		_printerror("unsetenv");
	}
	return (0);
}

#include "shell.h"

/**
 * _getpath - builds full path
 *
 * @command: argument to the path
 *
 * Return: full path
 */
char *_getpath(char *command)
{
	struct stat sb;
	int i = 0, j = 0;
	char *env = getenv("PATH"), *temp = NULL, *token = NULL, *s = NULL;

	if (env == NULL)
		return (NULL);
	s = _strdup(env);
	token = strtok(s, ":\n");
	while (token != NULL)
	{
		temp = malloc(_strlen(token) + _strlen(command) + 2);
		for (i = 0; (token[i] != '\0'); i++)
		{
			temp[i] = token[i];
		}
		temp[i++] = '/';
		for (j = 0; (command[j] != '\0'); j++)
		{
			temp[i] = command[j];
			j++;
		}
		temp[i] = '\0';
		if (stat(temp, &sb) == 0)
		{
			free(s);
			return (temp);
		}
		free(temp);
		token = strtok(NULL, ":\n");
	}
	free(s);
	return (NULL);
}


/**
 * _getenv - prints current environment
 * @args: parameter
 * @command: another parameter
 * Return: 0 if successful, otherwise 1
 */
int _getenv(char *command, char **args)
{
	int i = 0;

	if (_strcmp(command, "env") == 0)
	{
		for (; (environ != NULL) && (environ[i] != NULL); i++)
		{
			_puts(environ[i]);
		}
		if (args != NULL)
		{
			for (; (args[i] != NULL); i++)
				free(args[i]);
			free(args);
		}
		return (0);
	}
	return (1);
}

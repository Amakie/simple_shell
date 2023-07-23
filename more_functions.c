#include "shell.h"

/**
 * _exitfunc - frees allocated mem and return the exit status of a command
 * @command: pointer to the command string allocated by getline
 * @status: integer repping exit stsatus of the command
 * @args: pointer to an array of strings repping thr command args
 *
 * Return: status of the command
 */
void _exitfunc(char *command, int status, char **args)
{
	int i = 0;

	if (is_exit(command) == 0)
	{
		free(command);
		if (args != NULL && args[1] != NULL)
		{
			status = _atoi(args[1]);
			if (status <= 0)
				write(STDERR_FILENO, ": Illegal number: ", 18);
			status = (status <= 0) ? 2 : status;
			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}
		else
		{
			free(args[0]);
			free(args);
		}
		exit(status);
	}
}

/**
 * _tokenizer - splits a command string into an array of tokens
 * @command: pointer to the command string
 * @delim: pointer to a string containing the delimeters
 *
 * Return: pointer to an array of string (tokens)
 */
char **_tokenizer(char *command, char *delim)
{
	int i = 0;
	char *token = NULL, *temp = NULL;
	char **store_args = malloc(sizeof(char *) * 2048);

	if (!store_args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, delim);
	while (token != NULL)
	{

		if (i == 0 && token[0] != '/')
		{
			temp = _getpath(token);
			if (temp == NULL)
			{
				free(store_args);
				return (NULL);
			}
			store_args[0] = temp;
		}
		else
		{
			store_args[i] = malloc(_strlen(token) + 1);
			_strcpy(store_args[i], token);
		}
		token = strtok(NULL, delim);
		i++;
	}

	store_args[i] = NULL;
	return (store_args);
}

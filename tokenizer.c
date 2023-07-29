#include "shell.h"

/**
 * tokenizer - main function that...
 * @command: command
 * @delim: delimiter
 * Return: 0
 */

char **tokenizer(char *command, char *delim)
{
	char **store_args = malloc(sizeof(char *) * 2048);
	int i = 0;
	char *token = NULL, *temp = NULL, *save = NULL;

	if (!store_args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(command, delim, &save);
	while (token != NULL)
	{
		if (i == 0 && token[0] != '.' && !strcmp(token, "exit") == 0)
		{
			if (token[0] != '/')
			{
				temp = _getpath(token);
				if (temp == NULL)
				{
					free(store_args);
					return (NULL);
				}
				store_args[0] = _getpath(token);
				strcpy(store_args[i], temp);
				free(temp);
			}
			else
			{
				store_args[i] = malloc(_strlen(token) + 1);
				_strcpy(store_args[i], token);
			}
		}
		else
		{
			store_args[i] = malloc(_strlen(token) + 1);
			_strcpy(store_args[i], token);
		}
		i++;
		token = strtok_r(NULL, delim, &save);
	}
	store_args[i] = NULL;

	return (store_args);
}


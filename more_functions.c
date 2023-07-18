#include "shell.h"

/**
 * _exit - frees allocated mem and return the exit status of a command
 * @command: pointer to the command string allocated by getline
 * @status: integer repping exit stsatus of the command
 * @args: pointer to an array of strings repping thr command args
 *
 * Return: status of the command
 */
int _exit(char *command, int status, char **args)
{
	free_p((void **)&command);
	free_s(args);
	return (status);
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
	int bufsize = 64;
	int position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("Memory alllocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, delim);
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = (char **)_realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}

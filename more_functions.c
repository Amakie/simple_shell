#include "shell.h"

/**
 * _exit - frees allocated mem and return the exit status of a command
 * @command: pointer to the command string allocated by getline
 * @status: integer repping exit stsatus of the command
 * @args: pointer to an array of strings repping thr command args
 *
 * Return: status of the command
 */
void _exit(char *command, int status, char **args)
{
	int i = 0;
	if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't')
	{
		free(command);
		if (args != NULL && args[1] != NULL)
		{
			status = _atoi(args[1]);
			if (status <= 0)
				write(STDERR_FILENO, ": Illegal number: ", 18);
			status = (status <= 0) ? : status;
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

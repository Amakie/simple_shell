#include "shell.h"

/**
 * prompt - prints prompt in interactive mode
 *
 * Return: NULL
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * main - The main function
 * @argv: argument  vector
 * @argc: number of arguments passed
 * Return: 0 for success, -1 for failure
 */
int main(__attribute((unused))int argc, __attribute((unused))char **argv)
{
	struct stat sb;
	size_t length = 0;
	ssize_t r = 0;
	int i = 0, status = 0, command_ct = 1;
	char **args = NULL;
	char *command = NULL, *delim = " \t\n\r";

	while (TRUE)
	{
		prompt();
		r = getline(&command, &length, stdin);
		if (r == -1)
		{
			free(command);
			exit(0);
		}
		args = _tokenizer(command, delim);
		_exitfunc(command, status, args);
		if (_getenv(command, args) == 0)
			continue;
		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status = _error();
			else
				status = _child(args[0], args);
		}
		else if (args == NULL)
			status = _error();
		if (args != NULL)
		{
			for (; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		command_ct++;
	}
	return (0);
}

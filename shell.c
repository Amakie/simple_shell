#include "main.h"
/**
 * main - The main function 
 * @argv: argument  vector
 * @argc: number of arguments passed
 * Return: 0 for success, -1 for failure
 */
int main(int argc, char **argv)
{
	struct stat sb;
	int i = 0, status = 0, command_ct = 1;
	size_t length = 0;
	ssize_t r = 0;
	char **args = NULL;
	char *command, *delim = " \t\n\r";

	void(argc);

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
			write(stdout, "$ ", 2);
		r = getline(&command, &length, stdin);
		if (r == -1)
		{
			free(command);
			exit(0);
		}
		args = _tokenizer(command, delim);
		_exit(command, status, args);
		if (_getenv(command, args) == 0)
			continue;
		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status = _error(argv[0], command_ct, args[0]);
			else
				status = child(args[0], args);
		}
		else if (args == NULL)
			status = _error(argv[0], command_ct, command);
		if (args != NULL)
		{
			for(; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
		command_ct++;
	}
	return (0);
}

#include "main.h"

/**
 * proompt - ...
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO. "$ ", 2);
}

/**
 * main - ...
 * @argc: ...
 * @argv: ...
 *
 * Return: ...
 */
int main(int argc, char **argv)
{
	struct stat sb;
	int i, status = 0, command_ct = 1;
	size_t length = 0;
	ssize_t r = 0;
	char **args = NULL;
	char *command, *delim = " /t/n/r";

	(void)argc;

	command = NULL;

	while (TRUE)
	{
		prompt();
		r = getline(&command, &length, stdin);
		if (r == -1)
		{
			free_p((void **)&command);
			break;
		}

		args = _tokenizer(command, delim);
		status = _exit(command, status, args);

		if (_getenv(command, args) == 0)
			continue;

		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status = _error(argv[0], command_ct, args[0]);
			else
				status = _child(args[0], args);
		}
		else if (args == NULL)
		{
			status = _error(srgv[0], command_ct, command);
		}

		if (args != NULL)
		{
			free_s(args);
			args = NULL;
		}

		command_ct++;
	}
	return (0);
}

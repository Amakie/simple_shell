#include "shell.h"

/**
 * main - ,,,
 *
 * Return: ...
 */
int main(void)
{
	int i;
	struct stat sb;
	ssize_t r;
	int status = 0;
	char **args = NULL;
	char *command = NULL;
	size_t length = 0;

	while (TRUE)
	{
		promot();
		r = getline(&command, &length, stdin);
		if (r == -1)
		{
			free(command);
			exit(0);
		}
		args = _tokenizer(command, " \t\n\r");
		_exitfunc(command, status, args);
		if (args != NULL && args[0] != NULL)
		{
			if (stat(args[0], &sb) == -1)
				status = _error();
			else
				status = _child(args[0], args);
		}
		else if (args == NULL)
		{
			status = _error();
		}
		if (args != NULL)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
		}
	}
	return (0);
}

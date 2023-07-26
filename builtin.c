#include "shell.h"

/**
 * _error - prints error information
 *
 * Return: 127
 */
int _error(void)
{
	write(STDERR_FILENO, "not found\n", 10);
	return (127);
}

/**
 * _printerror - Prints an error message
 * @error: The error message to print
 * Return: Nothing
 */
void _printerror(char *error)
{
	size_t len;
	ssize_t num_written;

	len = _strlen(error);
	num_written = write(STDERR_FILENO, error, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
/**
 * is_exit - Is the command an exit command
 * @command: ...
 *
 * Return: 0 if it spells exit
 */
int is_exit(char *command)
{
	if (command[0] == 'e' && command[1] == 'x'
		&& command[2] == 'i' && command[3] == 't')
	{
		return (0);
	}
	else
		return (-1);
}

#include "shell.h"

/**
 * ch_dir - handles current working directory
 * @args: arguments
 * Return: Nothing
 */
void ch_dir(char **args)
{
	char *dir = args[1];
	int result;

	if (dir == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	result = chdir(dir);
	if (result == -1)
	{
		perror("cd");
	}
}


 #include "shell.h"

/**
 * check_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_builtin(char **args)
{
	if (!args[0])
		return (0);
	else if (!_strcmp(args[0], "setenv"))
		_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		_unsetenv(args);
	else if (!_strcmp(args[0], "cd"))
		ch_dir(args);
	else
		return (0);
	return (1);
}

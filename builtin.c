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
 * is_exit - Is the command an exit command
 *
 * Return: 0 if it spells exit
 */
int is_exit(char *command)
{
	if (command[0] == 'e' && command[1] == 'x' && command[2] == 'i' && command[3] == 't')
	{
		return (0);
	}
	else
		return (1);
}

#include "shell.h"

/**_error - prints error information
 *
 * Return: 127
 */
int _error(void)
{
	write(STDERR_FILENO, "not found\n", 10);
	return (127);
}


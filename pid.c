#include "shell.h"
/**
 * _child - function that creates the child process
 * @args: parameter
 * @token: token to the string
 * Return: Always 0
 */
int _child(char *token, char **args)
{
	char **env = environ;
	int pid_status = 0;
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(token, args, env) == -1)
		{
			perror("execute failed");
			return (1);
		}
	}
	else
	{
		wait(&pid_status);
		if (WIFEXITED(pid_status))
			pid_status = WEXITSTATUS(pid_status);
		if (!isatty(STDIN_FILENO))
			return (pid_status);
	}
	return (0);
}

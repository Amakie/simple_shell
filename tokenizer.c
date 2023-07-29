#include "shell.h"

/**
 * tokenizer - main function that...
 * @command: command
 * @delim: delimiter
 * Return: 0
 */

char **tokenizer(char *command, char *delim)
{
	char **store_args = malloc(sizeof(char *) * 2048);
	int i = 0;
	char *token = NULL, *temp = NULL, *save = NULL;

	if (!store_args)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok_r(command, delim, &save);
	while (token != NULL)
	{
		if (i == 0 && token[0] != '.' && !strcmp(token, "exit") == 0)
		{
			if (token[0] != '/')
			{
				temp = _getpath(token);
				if (temp == NULL)
				{
					free(store_args);
					return (NULL);
				}
				store_args[0] = _getpath(token);
				strcpy(store_args[i], temp);
				free(temp);
			}
			else
			{
				store_args[i] = malloc(_strlen(token) + 1);
				_strcpy(store_args[i], token);
			}
		}
		else
		{
			store_args[i] = malloc(_strlen(token) + 1);
			_strcpy(store_args[i], token);
		}
		i++;
		token = strtok_r(NULL, delim, &save);
	}
	store_args[i] = NULL;

	return (store_args);
}



/**
 * ch_dir - change directory
 * @args: arguments.
 * @front: A double pointer to the first element in args
 * Return: 0
 */
int ch_dir(char **args, __attribute((unused))char **front)
{
	char **dir_info, *new_line = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (create_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(1, pwd, _strlen(pwd));
		write(1, new_line, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}

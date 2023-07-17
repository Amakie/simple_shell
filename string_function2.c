#include "shell.h"

/**
 * _strcmp - ...
 * @s1: ...
 * @s2: ...
 *
 * Return: ...
 */
int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * _strcpy - ...
 * @dest: ...
 * @src: ...
 *
 * Return: ...
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - ...
 * @dest: ...
 * @src: ...
 *
 * Return: ...
 */
char *_strcat(char *dest, char *src)
{
	int c, c2;

	c = 0;
	while (dest[c])
		c++;

	for (c2 = 0; src[c2]; c2++)
	{
		dest[c++] = src[c2];
	}
	dest[c] = '\0';

	return (dest);
}

/**
 * _strncat - ...
 * @dest: ...
 * @src: ...
 * @n: ...
 *
 * Return: ...
 */
char *_strncat(char *dest, char *src, int n)
{
	int c, i;

	c = 0;
	while (dest[c])
		c++;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[c + i] = src[i];
	}
	dest[c + i] = '\0';

	return (dest);
}

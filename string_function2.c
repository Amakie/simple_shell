#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 *
 * Return: 0 if s1 == s2, -ve if s1 < s2, +ve if s1 > s2
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
 * _strcpy - copy a string from source to destination
 * @dest: destination to store the copied string
 * @src: source string to be copied
 *
 * Return: pointer to dest buffer
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
 * _strcat - concatenates two strings
 * @dest: destination to store the concatenated string
 * @src: the source string to be appended
 *
 * Return: a pointer to dest buffer
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
 * _strncat - concatenates two strings
 * (append at most n chars of source to dest)
 * @dest: destination tom store the concat string
 * @src: souce string to be appended
 * @n: number of bytes to be appended from src
 *
 * Return: pointer to dest
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

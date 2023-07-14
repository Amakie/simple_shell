#include "main.h"

/**
 * _memset - ...
 * @a: ...
 * @b: ...
 * @n: ...
 *
 * Return: ...
 */
char *_memset(char *a, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		a[i] = b;
	}
	return (a);
}

/**
 * free_s - free string of strings
 * @pp:
 *
 * Return: ...
 */
void free_s(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
	{
		free(*pp++);
	}
	free(a);
}

/**
 * _realloc - ...
 * @ptr: ...
 * @old: ...
 * @new_: ...
 *
 * Return: pointer to thr new allocated mem
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new_)
{
	char *p;

	if (!ptr)
		return (malloc(new_));
	if (!new_)
	{
		free(ptr);
		return (NULL);
	}
	if (new_ == old)
		return (ptr);

	p = malloc(new_);
	if (!p)
		return (NULL);

	old = old < new_ ? old : new_;
	while (old--)
		p[old] = ((char *)ptr)[old];
	free(ptr);
	return (p);
}

/**
 * free_p - frees a pointer and null the address
 * @ptr: ...
 *
 * Return: ...
 */
int free_p(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

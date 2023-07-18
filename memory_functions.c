#include "shell.h"

/**
 * _memset - fill memory are with a constant byte
 * @a: pointer to the mem to be filled
 * @b: the const byte to fill the mem area with
 * @n: number of bytes to fill
 *
 * Return: pointer to mem area of a
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
 * free_s - free mem aloocated for an array of pointers to strings
 * @pp: pointer to the array op pointers
 *
 * Return: void
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
 * _realloc - reallocates memory for a block of mem
 * @ptr: pointer to the old mem block
 * @old: size of the old mem block in bytes
 * @new_: size of the new mem block in bytes
 *
 * Return: pointer to thr new allocated mem or Null on failure
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
 * free_p - frees mem of a pointer to pointer
 * @ptr: double pointer to be freed
 *
 * Return: 1 on success, or 0 om failure
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

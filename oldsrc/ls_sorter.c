#include "ft_ls.h"

int ls_sort_default(const void *a, const void *b, void *arg)
{
	return strcmp (*(const char **) a, *(const char **) b);
}

int ls_sort_default(const char *a, const char *b)
{
	return (0);
}

int ls_sort_rev(const char *a, const char *b)
{
	return (0);
}
#ifndef FT_QSORT_H
#define FT_QSORT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../../libft.h"

# ifndef QSORT_CUTOFF
#  define QSORT_CUTOFF 1
# endif

void ft_voidswap(void *v1, void *v2, int size);
void ft_insertion_sort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));
void ft_qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

#endif
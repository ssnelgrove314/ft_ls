#ifndef FT_MERGESORT_H
# define FT_MERGESORT_H

#include "../../libft.h"
#include "../stack/ft_stack.h"

void ft_mergesort(t_node **head, int (*cmp)(void *, void *));

#endif
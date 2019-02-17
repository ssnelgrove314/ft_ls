#ifndef FT_QSORT
#define FT_QSORT

#include <string.h>
#include <alloca.h>
#include <stdlib.h>
#include <limits.h>

#define SWAP(a, b, size) \
	do \
	{ \
		size_t __size = (size); \
		char *__a = (a), *__b = (b); \
		do \
			{ \
				char __tmp = *__a; \
				*__a++ = *__b; \
				*__b++ = __tmp; \
			} while (--__size > 0); \
	} while (0) 

#define MAX_THRESH 4

typedef int (*ft_sorter)(const void *,const void *, void *);

typedef struct
{
	char *lo;
	char *hi;
} stack_node;

#define STACK_SIZE        (CHAR_BIT * sizeof(size_t))
#define PUSH(low, high)        ((void) ((top->lo = (low)), (top->hi = (high)), ++top))
#define POP(low, high)        ((void) (--top, (low = top->lo), (high = top->hi)))
#define STACK_NOT_EMPTY        (stack < top)

void ft_quicksort(void *const pbase, size_t total_elems, size_t size, ft_sorter sorter, void *arg);
#endif
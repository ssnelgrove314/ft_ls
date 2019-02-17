#ifndef FT_STACK_H
#define FT_STACK_H

#include "libft.h"

typedef struct s_stack{
	void **contents;
	int top;
	int maxSize;	
} t_stack;

void stack_init(t_stack *stack, int max_size);
void stack_destroy(t_stack *stack);
int stack_empty(t_stack *stack);
int stack_full(t_stack *stack);
void stack_push(t_stack *stack, void *elem);
void *stack_pop(t_stack *stack);

#endif
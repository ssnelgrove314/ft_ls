#include "ft_stack.h"

void stack_init(t_stack *stack, int max_size)
{
	void *new_content;

	new_content = (void **)ft_memalloc(sizeof(void *) * max_size);
	if (new_content == NULL)
	{
		printf("no mem");
		exit(1);
	}
	stack->contents = new_content;
	stack->maxSize = max_size;
	stack->top = -1;
}

void stack_destroy(t_stack *stack)
{
	free(stack->contents);
	stack->contents = NULL;
	stack->maxSize = 0;
	stack->top = -1;
}

int stack_empty(t_stack *stack)
{
	return (stack->top < 0);
}

int stack_full(t_stack *stack)
{
	return (stack->top >= stack->maxSize -1);
}

void stack_push(t_stack *stack, void *elem)
{
	if (stack_full(stack))
	{
		printf("stack is full");
		exit(1);
	}
	stack->contents[++stack->top] = elem;
}

void *stack_pop(t_stack *stack)
{
	if (stack_empty(stack))
	{
		printf("stack is empty yo");
		exit(1);
	}
	return (stack->contents[stack->top--]);
}
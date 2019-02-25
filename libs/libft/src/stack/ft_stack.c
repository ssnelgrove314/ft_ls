/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:45:03 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:52:04 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void			stack_init(t_stack *stack)
{
	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack->head = NULL;
	stack->size = 0;
}

int			stack_empty(t_stack *stack)
{
	return (stack->size == 0);
}

void			stack_push(t_stack *stack, void *content)
{
	t_node *new_elem;
	t_node *tmp;

	new_elem = (t_node *)ft_memalloc(sizeof(t_node));
	tmp = NULL;
	new_elem->content = content;
	tmp = stack->head;
	stack->head = new_elem;
	new_elem->next = tmp;
	stack->size++;
}

void			*stack_pop(t_stack *stack)
{
	void *pop;
	t_node *tmp;

	tmp = NULL;
	pop = NULL;
	if (!stack->head)
		return (NULL);
	pop = stack->head->content;
	tmp = stack->head;
	stack->head = stack->head->next;
	stack->size--;
	free (tmp);
	return (pop);
}

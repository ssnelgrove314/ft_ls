/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:48:46 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:49:06 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "../../libft.h"

typedef struct s_stack
{
	size_t size;
	t_node *head;
}		t_stack;

void			stack_init(t_stack *stack);
int				stack_empty(t_stack *stack);
void			stack_push(t_stack *stack, void *elem);
void			*stack_pop(t_stack *stack);

#endif

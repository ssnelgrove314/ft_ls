/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:15:57 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:23:13 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void			init_queue(t_queue *q)
{
	if (!q)
		return ;
	q->head = 0;
	q->tail = -1;
	q->size = 0;
}

void			enqueue(t_queue *q, void *item)
{
	if (!q)
		return ;
	if (full_queue(q))
		return ;
	(q->tail)++;
	(q->tail) %= QUEUE_CAPACITY;
	(q->data)[q->tail] = item;
	(q->size)++;
}

void			*dequeue(t_queue *q)
{
	void		*item;

	item = NULL;
	if (!q)
		return (item);
	if (empty_queue(q))
		return (item);
	item = (q->data)[q->head];
	(q->head)++;
	(q->head) %= QUEUE_CAPACITY;
	(q->size)--;
	return (item);
}

int				empty_queue(t_queue *q)
{
	if (!q)
		return (-1);
	return (q->size == 0);
}

int				full_queue(t_queue *q)
{
	if (!q)
		return (-1);
	return (q->size == QUEUE_CAPACITY);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 06:41:42 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 02:01:45 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** adds a new element to the head of the list
** changes the head pointer to the new element
*/

#include "ft_list.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

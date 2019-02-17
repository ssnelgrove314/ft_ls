/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memorywrite_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:50:04 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 16:51:04 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					memorywrite_module(t_input *input, va_list *ptr)
{
	int				*intptr;

	(void)input;
	intptr = va_arg(*ptr, int*);
	if (ptr)
		*intptr = write_flush(-2);
	return (1);
}

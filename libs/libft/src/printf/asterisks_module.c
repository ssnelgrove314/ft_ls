/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisks_module.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:49:16 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 16:50:42 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					asterisks_module(t_input *input, va_list *ptr)
{
	if (input->asterisks > 1)
	{
		input->width = va_arg(*ptr, int);
		input->precision = va_arg(*ptr, int);
	}
	else if (input->asterisks > 0)
		input->width = va_arg(*ptr, int);
	return (0);
}

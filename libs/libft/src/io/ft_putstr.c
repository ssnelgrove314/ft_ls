/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:05:14 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:14:34 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prints char str to the std output
*/

#include "libft.h"

void	ft_putstr(const char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

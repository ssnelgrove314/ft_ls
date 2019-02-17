/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:27:13 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 02:00:07 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes a string s and returns the int value of it
*/

#include "libft.h"

int	ft_atoi(char *s)
{
	int		is_neg;
	int		n;

	is_neg = 0;
	n = 0;
	while (ft_isspace(*s))
		s++;
	if (ft_strcmp(s, "-2147483648") == 0)
		return (-2147483648);
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		is_neg = 1;
		s++;
	}
	while (*s && ft_isdigit(*s))
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (is_neg ? -n : n);
}

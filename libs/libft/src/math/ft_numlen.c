/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 05:48:38 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:11:34 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes an int and gives the length of that int.
** eg ft_numlen(1234) = 4
*/

#include "libft.h"

int		ft_numlen(int n)
{
	int		len;
	long	nc;

	len = 0;
	nc = (long)n;
	if (nc <= 0)
	{
		len++;
		nc = -nc;
	}
	while (nc != 0)
	{
		len++;
		nc /= 10;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 05:04:42 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 06:29:42 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes a int n and returns the string version of it;
*/

#include "libft.h"

char	*ft_itoa(int n)
{
	int		numlen;
	long	nc;
	char	*str;

	numlen = ft_numlen(n);
	nc = (long)n;
	str = ft_strnew(numlen);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (nc < 0)
	{
		str[0] = '-';
		nc = -nc;
	}
	str[numlen--] = (nc % 10) + '0';
	while (nc >= 10)
	{
		nc /= 10;
		str[numlen--] = (nc % 10) + '0';
	}
	return (str);
}

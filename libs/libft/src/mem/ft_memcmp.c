/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:15:56 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:05:43 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compares byte string s1 against byte string s2. Both strings are assumed
** to be n bytes long.
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *st1;
	const unsigned char *st2;

	if (n == 0 || s1 == s2)
		return (0);
	st1 = (const unsigned char *)s1;
	st2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		if (n)
		{
			st1++;
			st2++;
		}
	}
	return (0);
}

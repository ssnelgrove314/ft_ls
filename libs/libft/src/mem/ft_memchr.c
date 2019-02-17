/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:15:51 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/08 00:53:54 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memchr:
** located the first occurance of c (converted to unsigned char)
** in memory *s that is size_t n;
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sp;

	sp = (unsigned char *)s;
	while (n-- != 0)
	{
		if (*sp == (unsigned char)c)
			return (sp);
		sp++;
	}
	return (NULL);
}

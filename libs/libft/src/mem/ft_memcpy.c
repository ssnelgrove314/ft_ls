/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:14:37 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 02:51:56 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies s2 into s1 for n bytes
*/

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*dst;
	char	*sc;
	size_t	i;

	dst = (char *)s1;
	sc = (char *)s2;
	i = 0;
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dst);
}

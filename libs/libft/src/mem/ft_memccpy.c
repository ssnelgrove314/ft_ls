/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:44:38 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:06:50 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @memccpy
** Copies string src into string dst, if int c is found, copy stops
** and a pointer to the byte after the found c is returned.
** If no c is found, n bytes are coppied and a null pointer is returned.
** 1. Set up pointers for dst, src and c.
** 2. cast c to unsigned char
** 3. Declar iterator to compare n to (size_t);
** 4. Copy THEN check if new dest is equal to c.
** 5. return pointer to byte after c || NULL
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*cs;
	unsigned char	*cd;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	cs = src;
	cd = dst;
	while (i < n)
	{
		cd[i] = cs[i];
		if (cd[i] == cc)
			return (&cd[i + 1]);
		i++;
	}
	return (NULL);
}

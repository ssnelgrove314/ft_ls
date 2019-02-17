/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:31:26 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 02:51:16 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memmove:
** Copies (size_t)len bytes from src to dst, the two strings may overlap
** the copy is done in a non destructive manner.
**
** placeholders for dst and src
** if src > dest, copy fwd. If dest > src, copy bwd.
**
** return dst;
*/

#include "libft.h"

static void		*ft_memcpy_bwd(void *s1, const void *s2, size_t n)
{
	const char	*s;
	char		*d;

	if (n == 0 || s1 == s2)
		return (s1);
	s = (const char *)s2;
	d = (char *)s1;
	while (n--)
	{
		d[n] = s[n];
	}
	return (d);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (src < dst)
		return (ft_memcpy_bwd(dst, src, len));
	return (NULL);
}

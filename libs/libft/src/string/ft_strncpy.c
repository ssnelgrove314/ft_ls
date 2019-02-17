/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 00:47:06 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 04:00:42 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copies at most N chars from src to dst.
** If src is less than N chars long, the remainder of dst is filled with '\0'
** Otherwise, dst is NOT terminated
** Does not garantee to NUL terminate the string.
** @Param1 destinating string.
** @Param2 src string to copy
** @Param3 the number of chars to copy
** @Return the final dst
*/
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

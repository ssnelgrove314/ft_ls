/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:04:40 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:20:43 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Locates the first occurence c (converted to a char) in the string pointed
** to by s. The terminating null char is part of the string.
** if c = '\0', the function locates the terminating '\0'
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}

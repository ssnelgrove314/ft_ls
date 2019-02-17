/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:10:16 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:56:54 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographically compare both strings for at most N characters.
** Since this is designed for strings, the '\0' are not compared.
** @Param1 a string to be compared
** @Param2 The other string
** @Param3 The number of chars to compare
** @Return an int >,<,== than zero. according to s1 >,<,== s2
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	return ((int)(n ? *(unsigned char *)s1 - *(unsigned char *)s2 : 0));
}

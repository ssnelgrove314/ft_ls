/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:09:43 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 04:07:17 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Located the first occurance of the null-terminated string needle in the
** null-terminated string haystack, where not more than N characters are
** searched. Characters that appear after a '\0' are not searched.
** @Param1 haystack
** @Param2 needle
** @Param3 number of characters to be searched.
** @Return if needle is empty, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	itn;
	char	*it1;
	char	*it2;

	if (!*s2)
		return ((void *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			itn = n;
			it1 = (void *)s1 + 1;
			it2 = (void *)s2 + 1;
			while (itn-- && *it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)s1);
		}
		s1++;
	}
	return (NULL);
}

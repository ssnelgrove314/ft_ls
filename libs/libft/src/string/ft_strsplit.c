/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:20:43 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:17:04 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained
** by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example
** : ft_strsplit("*hello*fellow***students*", ’*’) returns
** the array ["hello", "fellow", "students"]
** ft_strcpy_c (copies until it hits an occurance of c)
** ft_strlen_c (gets the strlen until it hits c)
** ft_nbstr_c finds the number of strings contained in the original string
*/

#include "libft.h"

static int		ft_strcpy_c(char *dest, char const *src, char c)
{
	int decalage;

	decalage = 0;
	while (*src && *src != c)
	{
		*dest = *src;
		++dest;
		++src;
		++decalage;
	}
	*dest = '\0';
	return (decalage);
}

static int		ft_strlen_c(char const *str, char c)
{
	int len;

	len = 0;
	while (*str && *str != c)
	{
		++str;
		++len;
	}
	return (len);
}

static int		ft_nbstr_c(char const *str, char c)
{
	int len;

	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str)
			++len;
		while (*str && *str != c)
			++str;
	}
	return (len);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**s1;
	int		i;

	if (!str)
		return (NULL);
	if (!(s1 = (char**)malloc(sizeof(*s1) * (ft_nbstr_c(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str && *str == c)
		++str;
	while (*str)
	{
		if (!(s1[i] = (char*)malloc(sizeof(**s1) * (ft_strlen_c(str, c) + 1))))
			return (NULL);
		str = str + ft_strcpy_c(s1[i], str, c);
		++i;
		while (*str && *str == c)
			++str;
	}
	s1[i] = 0;
	return (s1);
}

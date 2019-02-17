/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:20:03 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:24:56 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering
** to a valid substring, the behavior is undefined. If the
** allocation fails, the function returns NULL
** @Param1 the string from which create the substring
** @Param2 the start index of the substring
** @Param3 the length of the substring
** @Return the substring
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	sub = ft_strnew(len);
	i = 0;
	if (sub == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

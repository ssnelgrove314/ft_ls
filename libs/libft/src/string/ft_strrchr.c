/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:07:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 04:10:57 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locates the LAST occurence of c (converted to a char) in S. The terminating
** null character is considered to be part of the string; therefore if c is '\0'
** the function locates the terminating '\0'
** @Param1 the string that is being searched through.
** @Param2 the char that is being searched for
** @Return a pointer located to the last occurence of C or NULL if char does
** not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *result;

	result = NULL;
	while (1)
	{
		if (*s == c)
			result = (char *)s;
		if (*s++ == 0)
			break ;
	}
	return (result);
}

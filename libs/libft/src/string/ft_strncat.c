/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:18:22 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:52:55 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** append (at most n) copy of the null-term string s2 to the end of
** the null-term string s1 and then add a terminating '\0'
** The string s1 must have space to hold the result.
** @Param1 str to be concat
** @Param2 str to be put on the end of s1.
** @Param3 number of chars from s2 to append
** @Return pointer to s1
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ret;

	ret = s1;
	while (*s1)
		s1++;
	while (n-- && *s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (ret);
}

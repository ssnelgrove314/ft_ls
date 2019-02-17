/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:21:03 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:42:11 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending
** with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
** @Param1 The prefix string
** @Param2 The suffix string
** @Return The "Fresh" string result of the concatenation of the two strings.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concat = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (concat == NULL)
		return (NULL);
	ft_strcpy(concat, s1);
	return (ft_strcat(concat, s2));
}

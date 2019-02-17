/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:18:09 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:36:32 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographical comparison between s1 and s2. If the 2
** strings are identical the function returns 1, or 0 otherwise.
** @Param1 first string to be compared
** @Param2 second string to be compared
** @Return 1 or 0 according to if the strings are identical.
** NOTE: Not sure if that NULL check is technically correct. If both strings
** are NULL, then are they equal???
*/

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strcmp(s1, s2) == 0);
}

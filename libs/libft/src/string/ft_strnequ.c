/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:19:06 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 04:02:59 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographical comparison between s1 and s2 up to n characters
** or until a ’\0’ is reached. If the 2 strings are identical,
** the function returns 1, or 0 otherwise.
** @Param1 the first string to be compared
** @Param2 the second string to be compared
** @Param3 the max chars to be compared
** @Return 1 or 0, depending if they are identical or not.
** NOT SURE WHAT TO DO IF BOTH PARAMS ARE NULL
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}

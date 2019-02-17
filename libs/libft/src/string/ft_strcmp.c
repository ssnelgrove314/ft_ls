/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:04:35 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:23:35 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographically compare the null-terminating strings s1 and s2.
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	length1;
	size_t	length2;
	int		ret;

	length1 = ft_strlen(s1) + 1;
	length2 = ft_strlen(s2) + 1;
	length1 = (length1 <= length2) ? length1 : length2;
	ret = ft_memcmp(s1, s2, length1);
	return (ret);
}

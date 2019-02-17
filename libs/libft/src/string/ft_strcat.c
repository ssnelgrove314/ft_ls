/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:56:19 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:16:35 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then adds a terminating '\0'
** The string s1 must have sufficent space to hold the result
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *dp;

	dp = s1;
	while (*s1)
		s1++;
	while ((*s1++ = *s2++))
		;
	return (dp);
}

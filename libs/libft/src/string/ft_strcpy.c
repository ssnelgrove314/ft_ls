/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 00:54:22 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 06:24:39 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy the string src to dst (including the '\0' chars)
** The src and dst strings should not overlap. UNDEFINED
*/

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;
	char	*sc;

	i = 0;
	sc = (char *)src;
	while (sc[i] != '\0')
	{
		dest[i] = sc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

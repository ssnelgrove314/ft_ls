/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:40:20 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:13:17 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memset() function writes len bytes of value c
** (converted to an unsigned char) to the string b.
** @Param1 pointer to the address in memory
** @Param2 the value to write memory
** @Return the pointer to the newly set memory
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;

	s = b;
	while (len-- != 0)
		*s++ = (unsigned char)c;
	return (b);
}

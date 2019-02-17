/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:03:00 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:44:10 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns the length of a string.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

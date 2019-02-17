/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:01:08 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:21:36 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets every character of the string to '\0'
** Uses ft_bzero(void *s, size_t n) and ft_strlen(const char *s);
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero((void *)s, ft_strlen((const char *)s));
}

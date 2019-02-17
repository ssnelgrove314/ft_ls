/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:20:57 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:33:06 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocates sufficent memory for a copy of s1, does the copy and returns a
** pointer to it. The pointer may subsequently be used as an argument to the
** function free. If insufficent mem, NULL is returned.
** TMP IS NOT FREED BECAUSE OF STRDUP IMPLEMENTATION
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(src);
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	ft_strcpy(tmp, src);
	return (tmp);
}

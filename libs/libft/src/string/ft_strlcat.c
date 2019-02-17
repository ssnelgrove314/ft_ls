/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 00:40:18 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:43:15 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function takes char *dest and concatinates char *src to the end
** Appends the NUL-terminated string src to the end of dest:
** It will append at most size - ft_strlen(dest) - 1 bytes
**
** *dest = destination string, *src = source to cat on the end of dest
** size = size of dest;
**
** src_len, dest_len = length of the two strings
** i, j = iterators
**
** loops through src to get src_len;
** loops through dest to get dest_len and cheks to see if the size fits
** remaining = size - dest_len; (remaining space in dest to copy src)
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	remaining;
	int		i;
	int		j;

	i = 0;
	dest_len = 0;
	remaining = size;
	while (src[i] != '\0')
		i++;
	src_len = i;
	while (dest[dest_len] && remaining--)
		dest_len++;
	remaining = size - dest_len;
	if (remaining == 0)
		return (size + src_len);
	i = 0;
	j = dest_len;
	while (src[i] != '\0' && remaining-- > 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (src_len + dest_len);
}

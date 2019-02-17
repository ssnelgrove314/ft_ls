/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expandpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:25:52 by jkrause           #+#    #+#             */
/*   Updated: 2018/11/28 18:02:31 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void				*ft_expandwrite(void *new,\
					int newlen, void *src, int *srcsize)
{
	int				length;
	int				newlength;
	char			*newbuf;

	length = newlen;
	newlength = *srcsize + length;
	newbuf = (char*)malloc(newlength);
	ft_memcpy(newbuf, src, *srcsize);
	ft_memcpy(newbuf + *srcsize, new, newlen);
	*srcsize = newlength;
	if (src)
		free(src);
	return (newbuf);
}

char				*ft_expandpad(char c, int repeat, char *result, int *bsize)
{
	char			*tmp;

	tmp = ft_strnew(repeat);
	ft_memset(tmp, c, repeat);
	result = ft_expandwrite(tmp, repeat, result, bsize);
	free(tmp);
	return (result);
}

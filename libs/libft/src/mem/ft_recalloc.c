/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:40:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 16:42:18 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *ptr, size_t src_size, size_t new_size)
{
	void *new_ptr;

	if (!new_size)
	{
		if (ptr)
			free(ptr);
		return (ptr);
	}
	if (!ptr)
		return (ft_memalloc(new_size));
	if (new_size <= src_size)
		return (ptr);
	new_ptr = ft_memalloc(new_size);
	if (new_ptr)
	{
		ft_memcpy(new_ptr, ptr, src_size);
		free(ptr);
	}
	return (new_ptr);
}

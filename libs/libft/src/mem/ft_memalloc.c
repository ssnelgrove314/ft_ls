/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:56:11 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 06:41:54 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory
** area. The memory allocated is initialized to 0. If the allocation
** fails, the function returns NULL.
** @Param1 size of the memory that needs to allocated
** @Return the allocated memory area.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(size);
	if (!mem)
	{
		return (NULL);
	}
	ft_bzero(mem, size);
	return (mem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:50:44 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 06:40:56 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates fresh string ending with '\0'.
** Every other char is init to '\0'
** If allocation fails, returns NULL
** @Param1 the size of the string
** @Return the allocated string, or NULL if failed
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

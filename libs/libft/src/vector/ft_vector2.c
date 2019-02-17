/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:36:44 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:42:21 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vector_free(t_vector *vector)
{
	if (vector->data && vector->cap > 0)
	{
		free(vector->data);
		vector->data = NULL;
	}
}

void	ft_subvector_slide(t_vector *vector,\
		char *data, char *target, size_t data_len)
{
	VAR(int, orient, target >= data ? 1 : -1);
	VAR(char *, start, ~orient ? data : data + (data_len - 1));
	VAR(char *, subt, start + (orient * data_len));
	VAR(int, shifts, ~orient ? (target - subt) : (subt - target));
	if (shifts < (int)(~orient ? data_len : data_len - 1))
		return ;
	while (shifts-- != (~orient ? 0 : -1))
	{
		ft_charswap(start, subt);
		start += orient;
		subt += orient;
	}
	ft_subvector_slide(vector, start, target, data_len);
}

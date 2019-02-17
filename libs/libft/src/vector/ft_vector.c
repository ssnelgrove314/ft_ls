/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:35:29 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:37:31 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vectorspace_init(t_vector *vspace[], size_t init_cap, size_t size)
{
	VAR(size_t, i, -1);
	if (!vspace || !init_cap)
		return (-1);
	if (!(vspace = ft_memalloc(sizeof(t_vector *) * size)))
		return (-1);
	while (++i < size)
		if (~ft_vector_init(vspace[i], init_cap))
			continue ;
		else
		{
			free(vspace);
			return (-1);
		}
	return (0);
}

int		ft_vector_init(t_vector *vector, size_t init_cap)
{
	if (!vector || !init_cap)
		return (-1);
	vector->len = 0;
	vector->cap = init_cap;
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (-1);
	return (0);
}

void	ft_vector_append(t_vector *vector, char *newdata)
{
	size_t nd_len;

	nd_len = ft_strlen(newdata);
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_resize(t_vector *vector, size_t min)
{
	size_t	mllc_size;

	if (!(vector->data))
		ft_vector_init(vector, min);
	mllc_size = vector->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vector->data = (char *)ft_recalloc(vector->data, vector->len, mllc_size);
	vector->cap = mllc_size;
}

void	ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	size_t nd_len;

	nd_len = n;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

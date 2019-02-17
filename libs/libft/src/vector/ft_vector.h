/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:22:02 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:39:38 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "../../libft.h"

typedef struct		s_vector
{
	size_t			len;
	size_t			cap;
	char			*data;
}					t_vector;

void				ft_subvector_slide(t_vector *vector, char *data,
					char *target, size_t data_len);
int					ft_vector_init(t_vector *vector, size_t init_cap);
void				ft_vector_append(t_vector *vector, char *newdata);
void				ft_vector_resize(t_vector *vector, size_t min);
void				ft_vector_nappend(t_vector *vector, char *newdata,
					size_t n);
void				ft_vector_free(t_vector *vector);

#endif

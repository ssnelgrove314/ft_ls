/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:05:16 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/14 14:28:35 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef struct	s_node
{
	void *content;
	struct s_node *next;
}				t_node;

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdint.h>

# include "macrosoft.h"
# include "src/ctype/ctype.h"
# include "src/mem/mem.h"
# include "src/stack/ft_stack.h"
# include "src/string/ft_string.h"
# include "src/math/ft_math.h"
# include "src/list/ft_list.h"
# include "src/io/ft_io.h"
# include "src/stdlib/ft_stdlib.h"
# include "src/vector/ft_vector.h"
# include "src/queue/ft_queue.h"
# include "src/get_next_line/get_next_line.h"
# include "src/printf/ft_printf.h"
# include "src/mergesort/ft_mergesort.h"

#endif

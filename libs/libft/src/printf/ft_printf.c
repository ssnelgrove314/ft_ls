/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:49:43 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 16:50:57 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_input				*search(char *fmt)
{
	char				*search;
	t_input				*parsed;

	search = fmt;
	parsed = 0;
	while (*search != '\0')
	{
		search = ft_strchr(fmt, '%');
		if (search == 0)
			break ;
		parsed = (t_input*)ft_memalloc(sizeof(t_input));
		module_call(PARSEMODULE_PARSE, parsed, search);
		parsed->original = search;
		return (parsed);
	}
	return (0);
}

int					ft_printf(const char *fmt, ...)
{
	va_list				start;
	t_input				*iflag;
	char				*current;

	current = (char*)fmt;
	module_init();
	va_start(start, fmt);
	while ((iflag = search(current)) != 0)
	{
		write_module(ft_strsub(current, 0, (iflag->original - current)), 1, 0);
		module_call(ASTERISKMODULE_PARSE, iflag, &start);
		if (iflag->error || module_call(iflag->type, iflag, &start) == 0)
		{
			write_flush(-1);
			free(iflag);
			return (0);
		}
		current += (iflag->original - current) + iflag->input_length + 1;
		free(iflag);
	}
	va_end(start);
	return (write_flush(0));
}

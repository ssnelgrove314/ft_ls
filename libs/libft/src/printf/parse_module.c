/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:45:51 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 16:45:59 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** Function: check_flags
** Return: void
** Params: input struct and &fmt
** Description: checks and sets all flags for the other modules to use.
*/

void				check_flags(t_input *input, char **fmt)
{
	char				fc;

	fc = **fmt;
	while (CMP(fc, '-') || CMP(fc, '+') || CMP(fc, ' ')
			|| CMP(fc, '0') || CMP(fc, '#'))
	{
		if (fc == ' ')
			input->flag_all_signs_char != '+'
				? input->flag_all_signs_char = ' ' : 0;
		if (fc == '+')
			input->flag_all_signs_char = '+';
		if (fc == '#')
			input->flag_alt_mode = 1;
		if (fc == '0')
			input->flag_zero_pad = 1;
		if (fc == '-')
			input->flag_left_justify = 1;
		*fmt += 1;
		fc = **fmt;
	}
}

/*
** Function: check_widthcision
** Return: void
** Params: input struct and &fmt
** Description: Checks and sets width and precision for the input struct.
** used by the format module.
*/

void				check_widthcision(t_input *input, char **fmt)
{
	int					tmp;
	char				fc;

	tmp = 0;
	fc = **fmt;
	while ((fc >= '0' && fc <= '9') || fc == '.' || fc == '*')
	{
		input->asterisks += (fc == '*' ? 1 : 0);
		if (fc == '.')
		{
			input->width = tmp;
			input->precision = 0;
			tmp = 0;
			if (*(*fmt + 1) < '0' || *(*fmt + 1) > '9')
				return (void)(*fmt += 1);
		}
		else
			tmp += fc - '0';
		if (*(*fmt + 1) >= '0' && *(*fmt + 1) <= '9')
			tmp *= 10;
		*fmt += 1;
		fc = **fmt;
	}
	input->width != INT_MIN ? input->precision = tmp : 0;
	input->width == INT_MIN ? input->width = tmp : 0;
}

/*
** Function: check_length_hijacked
** Return: void
** Params: input struct and &fmt
** Description: Checks the length modifiers and sets them for the format module
*/

void				check_length_hijacked(t_input *input, char **fmt)
{
	char				fc;

	fc = **fmt;
	if (CMP(fc, 'h') || CMP(fc, 'l') || CMP(fc, 'j')
			|| CMP(fc, 'z') || CMP(fc, 't'))
	{
		if (fc == 'h' || fc == 'l')
			if (*(*fmt + 1) == 'h' || *(*fmt + 1) == 'l')
				input->length_extended = 1;
		input->length = fc;
		*fmt += input->length_extended ? 2 : 1;
		fc = **fmt;
	}
	if (**fmt == '*')
	{
		input->asterisks += 1;
		*fmt += 1;
	}
}

/*
** Function: parse_module
** Return: 1
** Params: input and a pointer offset (used with search)
** Description: This module parses all flags, width, length, precision and
** conversion spec
** It sets all the values in input so they can be used by format module
*/

int					parse_module(t_input *input, void *ptr)
{
	char				*alpha;
	char				*fmt;

	alpha = "sSpdDioOuUxXcCn%";
	input->width = INT_MIN;
	input->precision = INT_MIN;
	input->asterisks = 0;
	fmt = (char*)ptr + 1;
	check_flags(input, &fmt);
	check_widthcision(input, &fmt);
	check_length_hijacked(input, &fmt);
	while (*alpha != '\0')
	{
		if (*alpha == *fmt)
		{
			input->type = *alpha;
			input->error = 0;
			break ;
		}
		alpha += 1;
	}
	if (!input->type)
		input->error = 1;
	input->input_length = (fmt - (char*)ptr);
	return (1);
}

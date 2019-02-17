/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isxdigit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 07:15:14 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:21:35 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns 1 if the char c is a hex digit
*/

int	ft_isxdigit(int c)
{
	char	*digits;
	char	current;

	digits = "0123456789ABCDEFabcdef";
	current = (char)c;
	while (*digits)
	{
		if (current == *digits)
			return (1);
		digits++;
	}
	return (0);
}

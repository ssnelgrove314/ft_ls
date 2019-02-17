/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:57:07 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:24:33 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	char *spaces;

	spaces = "\t\n\v\f\r ";
	while (spaces)
	{
		if (*spaces == (char)c)
			return (1);
		spaces++;
	}
	return (0);
}
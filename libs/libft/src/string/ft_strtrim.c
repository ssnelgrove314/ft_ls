/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 03:34:00 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 10:20:56 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates and returns a copy of the string given as an arg w/o whitespaces
** at the begining or the end of the string. ' ', '\n', '\t' are considered
** spaces.
** @Param1 the string to trim
** @Return the trimmed string
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	char		*str;
	size_t		head;
	size_t		tail;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (!s[i])
		return (ft_strnew(0));
	head = i;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	tail = i + 1;
	str = ft_strnew(tail - head);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, &s[head], tail - head);
	return (str);
}

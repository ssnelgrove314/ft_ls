/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 00:47:41 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 09:21:15 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Located the first occurance of the null-terminated string needle in the
** null-terminated string haystack. Characters that appear after a '\0'
** are not searched.
** @Param1 haystack
** @Param2 needle
** @Return if needle is empty, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurence of needle is returned.
*/

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int find_index;
	int remember;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		find_index = 0;
		if (str[i] == to_find[find_index])
		{
			remember = i;
			while (str[i] == to_find[find_index])
			{
				if (to_find[find_index + 1] == '\0')
					return (&str[remember]);
				find_index++;
				i++;
			}
			i = remember;
		}
		i++;
	}
	return (0);
}

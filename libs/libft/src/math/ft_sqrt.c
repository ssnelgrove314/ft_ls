/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:08:11 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 09:18:01 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the floor of the square root of x
*/

#include "libft.h"

int	ft_sqrt(int num)
{
	int	start;
	int	end;
	int	ans;
	int	mid;

	start = 1;
	end = num;
	ans = 0;
	mid = 0;
	if (num == 0 || num == 1)
		return (num);
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == num)
			return (mid);
		if (mid * mid < num)
		{
			start = mid + 1;
			ans = mid;
		}
		else
			end = mid - 1;
	}
	return (ans);
}

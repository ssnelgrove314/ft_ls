/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 07:03:49 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/03/12 03:08:02 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the greatist common denominator of a for b
*/

#include "libft.h"

int	ft_gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (ft_gcd(b, a % b));
}

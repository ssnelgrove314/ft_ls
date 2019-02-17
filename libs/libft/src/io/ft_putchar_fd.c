/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:47:31 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/02/26 15:53:45 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the char c to the file descriptor fd
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

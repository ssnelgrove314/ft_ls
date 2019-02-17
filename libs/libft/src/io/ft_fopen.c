/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:58:14 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 18:03:29 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_fopen(const char *filename, const char *mode)
{
	int	fd;

	fd = 0;
	if (ft_strcmp("r", mode) == 0)
		fd = open(filename, O_RDONLY);
	else if (ft_strcmp("w", mode) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	else if (ft_strcmp("a", mode) == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND);
	else if (ft_strcmp("r+", mode) == 0)
		fd = open(filename, O_RDWR);
	else if (ft_strcmp("w+", mode) == 0)
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC);
	else if (ft_strcmp("a+", mode) == 0)
		fd = open(filename, O_RDWR | O_CREAT | O_APPEND);
	else
	{
		ft_putendl("Usage: A valid filename to open and a mode to open it in.");
		ft_putendl("Modes: [r,w,a,r+,w+,a+]");
	}
	return (fd);
}

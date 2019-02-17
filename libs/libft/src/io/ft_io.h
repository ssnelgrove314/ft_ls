/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssnelgro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:57:41 by ssnelgro          #+#    #+#             */
/*   Updated: 2018/11/28 17:58:02 by ssnelgro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include "../../libft.h"

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_fopen(const char *filename, const char *mode);
void				*ft_expandwrite(void *news,\
					int newlen, void *src, int *srcsize);
char				*ft_expandpad(char c, int repeat, char *result, int *bsize);
char				*ft_ltostr_base(void *value,\
					int base, char *alpha, int sign);

#endif

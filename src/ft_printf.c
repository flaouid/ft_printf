/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:09:52 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/10 10:29:29 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int				ft_vdprintf(int fd, const char *format, va_list args)
{
	char		*cpy;
	int			write;
	int			ret;

	cpy = (char*)format;
	write = 0;
	ret = write_again(fd, cpy, args, &write);
	return (ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vdprintf(fd, format, args);
	va_end(args);
	return (ret);
}

int				ft_vprintf(const char *format, va_list args)
{
	int			ret;

	ret = ft_vdprintf(1, format, args);
	return (ret);
}

int				ft_printf(const char *s, ...)
{
	va_list		args;
	int			ret;

	ret = 0;
	va_start(args, s);
	ret = ft_vdprintf(1, s, args);
	va_end(args);
	return (ret);
}

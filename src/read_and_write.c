/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:16:41 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/08 13:23:12 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		ft_putnstr_fd(int fd, char *cpy, size_t *n, int *print)
{
	if (cpy)
	{
		write(fd, cpy - *n, *n);
		*print += *n;
		*n = 0;
	}
}

int			write_again(int fd, char *cpy, va_list args, int *write)
{
	int		ret;
	size_t	n;

	n = 0;
	ret = 0;
	while (*cpy)
	{
		if (*cpy != '%')
			n++;
		else
		{
			if (n)
			{
				ret += n;
				ft_putnstr_fd(fd, cpy, &n, write);
			}
			ret += parse_arg(fd, &cpy, args, write);
		}
		cpy++;
	}
	ret += n;
	ft_putnstr_fd(fd, cpy, &n, write);
	return (ret);
}

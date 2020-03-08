/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:13:06 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/08 12:49:40 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			print_arg(int fd, t_params *pr, int *print, int i)
{
	char	c;
	int		ret;

	print = print + ft_strlen(pr->str);
	write(fd, pr->str, ft_strlen(pr->str));
	ret = ft_strlen(pr->str);
	if (pr->char_null)
	{
		if (!pr->width)
			!pr->width ? print = print + 1 : print + pr->width;
		else
		{
			if (pr->width && !pr->minus)
			{
				c = pr->zero ? '0' : ' ';
				while (++i < pr->width)
				{
					ret++;
					write(fd, &c, 1);
				}
			}
		//	print = print + pr->width;
		}
		ft_putchar(0);
	}
	return (!pr->char_null ? ret : ret + 1);
}

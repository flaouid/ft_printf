/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:13:06 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/10 17:34:04 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			print_arg(int fd, t_params *pr, int *print, int i)
{
	char	c;
	int		ret;

	(void)i;
	(void)c;
	print = print + ft_strlen(pr->str);
	if (pr->minus == 0)
		write(fd, pr->str, ft_strlen(pr->str));
	ret = ft_strlen(pr->str);
	if (pr->char_null)
	{
		if (!pr->width)
			print = print + 1;
		ft_putchar('\0');
	}
	if (pr->minus == 1)
		write(fd, pr->str, ft_strlen(pr->str));
	return (!pr->char_null ? ret : ret + 1);
}

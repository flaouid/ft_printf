/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:28:07 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/15 16:45:57 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return (ft_putstr_fd("(null)", fd));
	i = ft_strlen(s);
	write(fd, s, i);
}

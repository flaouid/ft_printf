/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:26 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 16:27:34 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buffer;
	size_t		i;

	i = 0;
	buffer = (const char*)s;
	while (i < n)
	{
		if (buffer[i] == c)
			return ((void*)&buffer[i]);
		i++;
	}
	return (NULL);
}

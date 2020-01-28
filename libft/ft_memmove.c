/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:38:57 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 16:26:45 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	if (len != 0)
	{
		if (dst <= src)
			ft_memcpy(dst, src, len);
		else
		{
			dest = (unsigned char*)dst;
			source = (unsigned char*)src;
			i = len;
			while (i-- != 0)
			{
				dest[i] = source[i];
			}
		}
	}
	return (dst);
}

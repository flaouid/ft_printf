/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:35:50 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 16:40:36 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	cmp;
	unsigned char	*dest;
	unsigned char	*source;

	if (n != 0)
	{
		i = 0;
		cmp = (unsigned char)c;
		dest = (unsigned char*)dst;
		source = (unsigned char*)src;
		while (i < n)
		{
			dest[i] = source[i];
			if (source[i] == cmp)
				return (dest + i + 1);
			i++;
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:01:52 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/13 17:50:17 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	cpy;
	size_t	srclen;

	cpy = 0;
	while (dst[cpy] != '\0')
		cpy++;
	i = 0;
	srclen = 0;
	while (src[i] != '\0' && cpy + i < size - 1)
	{
		if (size != 0)
			dst[cpy + i] = src[i];
		i++;
		srclen++;
	}
	if (size != 0)
		dst[cpy + i] = '\0';
	while (src[srclen] != '\0')
		srclen++;
	if (size < cpy)
		return (srclen + size);
	return (cpy + srclen);
}

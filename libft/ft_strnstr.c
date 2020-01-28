/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:04:40 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/18 17:03:16 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	while (haystack[i] != '\0' && i <= len)
	{
		i2 = 0;
		while (haystack[i + i2] == needle[i2] &&
		haystack[i + i2] && i + i2 < len)
			i2++;
		if (needle[i2] == '\0')
			return ((char*)haystack + i);
		i++;
	}
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	return (NULL);
}

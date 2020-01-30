/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:59:53 by flaouid           #+#    #+#             */
/*   Updated: 2020/01/30 17:09:08 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(const char *s1, const char *s2)
{
	char			*dest;
	unsigned int	length;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1);
	dest = (char*)malloc(length + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	ft_strcpy(dest + length, s2);
	return (dest);
}

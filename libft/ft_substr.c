/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:24:30 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 16:56:44 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if ((size_t)start > len)
	{
		str[i] = '\0';
		free(str);
		return (str);
	}
	while (i < len && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

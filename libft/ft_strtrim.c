/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:26:22 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/13 17:06:49 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isset(char str1, char const *charset)
{
	int				i;

	i = 0;
	while (charset[i])
	{
		if (str1 != charset[i])
			i++;
		else
			return (1);
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*output;

	if (s1 == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	while (ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	if (end - 1 > start)
		end--;
	while (end > start && ft_isset(s1[end], set))
		end--;
	output = (char*)malloc(end - start + 2);
	if (output == NULL)
		return (NULL);
	output[end - start + 1] = '\0';
	return (ft_memcpy(output, s1 + start, end - start + 1));
}

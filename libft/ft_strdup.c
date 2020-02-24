/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:12:32 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/24 17:29:30 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	if (dest != '\0')
	{
		return (dest);
	}
	free(dest);
	return (0);
}

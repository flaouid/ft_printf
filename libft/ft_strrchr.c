/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:07:57 by flaouid           #+#    #+#             */
/*   Updated: 2019/11/13 17:21:15 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	while (s[i] != '\0')
		i++;
	p = (char *)&s[i];
	while (i >= 0)
	{
		if (c == s[i])
			return (p);
		p--;
		i--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:00:58 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 16:34:42 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	char	*tmp;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		tmp = ft_strjoin(str, ft_itoa(-n));
		free(str);
		str = tmp;
	}
	else if (n > 10)
	{
		tmp = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		free(str);
		str = tmp;
	}
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}

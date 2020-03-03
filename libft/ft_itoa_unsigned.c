/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:25 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/03 13:11:22 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	char	*tmp;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		tmp = ft_strjoinf(str, ft_itoa_unsigned(-n));
		free(str);
		str = tmp;
	}
	else if (n >= 10)
	{
		tmp = ft_strjoinf(ft_itoa_unsigned(n / 10), ft_itoa_unsigned(n % 10));
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

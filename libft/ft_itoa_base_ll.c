/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:00 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/08 16:36:33 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base_ll(unsigned long long n, char *base)
{
	char		*str;
	char		*tmp;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		tmp = ft_strjoinf(str, ft_itoa_base_ll(-n, base));
		str = tmp;
	}
	else if (n >= (unsigned int)ft_strlen(base))
	{
		tmp = ft_strjoinf(ft_itoa_base_ll(n / ft_strlen(base), base),
		ft_itoa_base_ll(n % ft_strlen(base), base));
		free(str);
		str = tmp;
	}
	else if (n < (unsigned int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}

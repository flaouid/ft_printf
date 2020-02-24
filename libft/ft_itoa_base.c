/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/24 16:52:31 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(unsigned int n, char *base)
{
	char		*str;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		free(str);
		str = ft_strjoin(str, ft_itoa_base(-n, base));
	}
	else if (n >= (unsigned int)ft_strlen(base))
	{
		free(str);
		str = ft_strjoin(ft_itoa_base(n / ft_strlen(base), base),
			ft_itoa_base(n % ft_strlen(base), base));
	}
	else if (n < (unsigned int)ft_strlen(base) && n >= 0)
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/03 13:11:51 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(unsigned int n, char *base)
{
	char		*str;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	while (str)
	{
		if (n < 0)
		{
			str[0] = '-';
			str[1] = '\0';
			str = ft_strjoinf(str, ft_itoa_base(-n, base));
		}
		else if (n >= (unsigned int)ft_strlen(base))
		{
			str = ft_strjoinf(ft_itoa_base(n / ft_strlen(base), base),
			ft_itoa_base(n % ft_strlen(base), base));
		}
		else if (n < (unsigned int)ft_strlen(base) && n >= 0)
		{
			str[0] = base[n];
			str[1] = '\0';
		}
	}
		return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 16:30:18 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(unsigned int n, char *base)
{
	char		*str;
	char		*tmp;

	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
		return (NULL);
	while (str)
	{
		if (n < 0)
		{
			str[0] = '-';
			str[1] = '\0';
			tmp = ft_strjoin(str, ft_itoa_base(-n, base));
			free(str);
			str = tmp;
		}
		else if (n >= (unsigned int)ft_strlen(base))
		{
			tmp = ft_strjoin(ft_itoa_base(n / ft_strlen(base), base),
			ft_itoa_base(n % ft_strlen(base), base));
			free(str);
			str = tmp;
		}
		else if (n < (unsigned int)ft_strlen(base) && n >= 0)
		{
			str[0] = base[n];
			str[1] = '\0';
		}
	}
		return (str);
}

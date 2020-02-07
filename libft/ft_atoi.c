/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:25:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/07 11:37:13 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	long	result;

	result = 0;
	is_neg = 1;
	i = 0;
	while (*str == ' ' || (*str >= 8 && *str <= 13))
		str++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]) && str[i])
		{
			result = (result * 10) - (str[i++] - '0');
			if (result > 0)
				return (is_neg == -1 ? 0 : -1);
		}
		return ((int)(result * (is_neg * -1)));
	}
	else
		return (0);
}


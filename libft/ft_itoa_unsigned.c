/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:06:25 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/24 16:52:18 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*output;

	if (!(output = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		output[0] = '-';
		output[1] = '\0';
		free(output);
		output = ft_strjoin(output, ft_itoa_unsigned(-n));
	}
	else if (n >= 10)
		output = ft_strjoin(ft_itoa_unsigned(n / 10), ft_itoa_unsigned(n % 10));
	else if (n < 10 && n >= 0)
	{
		output[0] = n + '0';
		output[1] = '\0';
	}
	return (output);
}

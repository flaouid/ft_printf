/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:00:58 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 16:03:17 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*output;

	if (!(output = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (output = ft_strdup("-2147483648"));
	if (n <= 0)
	{
		output[0] = '-';
		output[1] = '\0';
		output = ft_strjoin(output, ft_itoa(-n));
	}
	else if (n >= 10)
		output = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n > 0)
	{
		output[0] = n + '0';
		output[1] = '\0';
	}
	return (output);
}

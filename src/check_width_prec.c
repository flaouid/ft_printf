/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:02:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/02/22 13:04:18 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		parse_width(t_params *pr)
{
	int		len;

	len = ft_strlen(pr->str);
	if (pr->width > len)
	{
		if (pr->minus)
		{
			add_str(&(pr->str), pr->zero > 0 ? '0' : ' ', pr->width - len, 0);
		}
		else
		{
			add_str(&(pr->str), pr->zero > 0 ? '0' : ' ', pr->width - len, 1);
		}
	}
}

void		parse_precision(t_params *pr)
{
	char	*str;

	if (pr->var_type == STR)
	{
		if (pr->precision < (int)ft_strlen(pr->str) && pr->precision > 0)
		{
			str = ft_substr(pr->str, 0, pr->precision);
			pr->str = str;
		}
	}
	else if (pr->str && pr->precision >= (int)ft_strlen(pr->str))
	{
		if (pr->str[0] == '+' || pr->str[0] == '-')
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str) + 1, 1);
		else
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str), 1);
	}
}

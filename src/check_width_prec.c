/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:02:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/04/13 11:16:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		parse_width(t_params *pr)
{
	int		len;

	len = ft_strlen(pr->str);
//	printf("pr->zero = %d && pr->precision = %d\n", pr->zero, pr->precision);
	if (pr->width > len)
	{
		if (pr->minus < 0)
			add_str(&(pr->str), pr->zero ? '0' : ' ', pr->width - len, 1);
		if (pr->minus > 0)
			add_str(&(pr->str), pr->zero ? '0' : ' ', pr->width - len, 0);
		else if (pr->type == 'p' && !pr->precision)
			add_str(&(pr->str), pr->zero ? '0' : ' ', pr->width - len, 1);
		else if (!pr->precision && pr->type != 'c' && pr->type != 's')
			add_str(&(pr->str), ' ', pr->width - len, 1);
		else
			add_str(&(pr->str), pr->zero ? '0' : ' ', pr->width - len, 1);
	}
}

void		parse_precision(t_params *pr)
{
	char	*str;

	if (pr->var_type == STR)
	{
		if (pr->precision <= (int)ft_strlen(pr->str) && pr->precision > 0)
		{
			str = ft_substr(pr->str, 0, pr->precision);
			free(pr->str);
			pr->str = str;
		}
	}
	else if (pr->str && pr->precision >= (int)ft_strlen(pr->str))
	{
		if (pr->str[0] == '+' || pr->str[0] == '-')
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str) + 1, 1);
		else if (pr->str[0] == '%' && !pr->width)
			add_str(&(pr->str), ' ', pr->width - ft_strlen(pr->str) + 1, 0);
		else if (pr->str[0] == '%')
			add_str(&(pr->str), ' ', pr->width - ft_strlen(pr->str) + 1, 1);
		else
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str), 0);
	}
}

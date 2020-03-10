/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:59:49 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/10 13:00:43 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		check_flags(char c, t_params *pr)
{
	if (c == '#')
		pr->hash = 1;
	else if (c == '0')
		pr->zero = 1;
	else if (c == ' ')
		pr->space = 1;
	else if (c == '+')
		pr->plus = 1;
	else if (c == '-')
		pr->minus = 1;
}

void		flags_width_prec(char **cpy, t_params *pr, va_list args)
{
	if (**cpy == '.')
	{
		(*cpy)++;
		pr->precision = 0;
		if (**cpy == '*')
		{
			check_star(args, pr, STAR_PREC);
			(*cpy)++;
			check(cpy, pr, args);
			return ;
		}
		pr->precision = ft_atoi(*cpy);
	}
	else
		pr->width = ft_atoi(*cpy);
	while (ft_isdigit(**cpy))
		(*cpy)++;
	check(cpy, pr, args);
}

void		check_star(va_list args, t_params *pr, int i)
{
	int		ret;

	ret = va_arg(args, int);
	if (i == STAR_PREC)
	{
		if (!ret)
			pr->precision = 0;
		else if (ret < 0)
			pr->precision = -1;
		else
			pr->precision = ret;
		return ;
	}
	else if (i == STAR_WIDTH)
	{
		if (ret < 0)
		{
			pr->minus = 1;
			ret = -ret;
		}
		pr->width = ret;
	}
}

void		check(char **cpy, t_params *pr, va_list args)
{
	if (ft_ischarset(**cpy, "cspdiuxX%"))
		pr->type = **cpy;
	else if (ft_ischarset(**cpy, "#0 +-"))
	{
		check_flags(**cpy, pr);
		(*cpy)++;
		check(cpy, pr, args);
	}
	else if ((**cpy == '.' || ft_isdigit(**cpy)))
		flags_width_prec(cpy, pr, args);
	else if (**cpy == '*')
	{
		check_star(args, pr, STAR_WIDTH);
		(*cpy)++;
		check(cpy, pr, args);
	}
}

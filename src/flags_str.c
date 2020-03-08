/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:06:59 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/08 16:39:42 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void					flags_str(va_list args, t_params *pr)
{
	char				*temp;

	temp = va_arg(args, char *);
	if (pr->type == 's' && temp)
		pr->str = ft_strdup(temp);
	else if (pr->type == 's' && !temp)
		pr->str = ft_strdup("(null)");
	if (pr->precision == 0)
		ft_strdel(pr->str);
}

void					flags_char(va_list args, t_params *pr)
{
	char				*str;

	if (pr->type == 'c')
	{
		str = (char*)malloc(2);
		str[0] = (char)va_arg(args, int);
		str[1] = '\0';
		if (!str[0])
			pr->char_null = 1;
		pr->str = str;
	}
}

void					flags_int_ll(va_list args, t_params *pr)
{
	unsigned long long	nb;
	char				base[17];
	char				*tmp;

	check_base(base, pr);
	nb = va_arg(args, unsigned long long);
	if (pr->type == 'p')
	{
		pr->str = ft_calloc(sizeof(char), 3);
		move_x(pr);
		if (pr->precision == -1 && !nb)
			tmp = ft_strjoinf(pr->str, ft_strdup("0"));
		else if (pr->precision >= 0 && !nb)
		{
			tmp = ft_strjoinf(pr->str, "");
			free(pr->str);
		}
		else
			tmp = ft_strjoinf(pr->str, ft_itoa_base_ll(nb, base));
		pr->str = tmp;
	}
}

void					flags_int_ll_x(va_list args, t_params *pr)
{
	unsigned long long	nb;
	char				base[17];

	check_base(base, pr);
	nb = va_arg(args, unsigned long long);
	if ((pr->type == 'x' || pr->type == 'X') && (!nb || nb == 0))
	{
		if (pr->precision >= 0)
			pr->str = ft_strdup("");
		else
			pr->str = ft_strdup("0");
	}
	else
		pr->str = ft_itoa_base_ll(nb, base);
}

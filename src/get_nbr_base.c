/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:11:13 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 16:46:12 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void				check_base(char base[17], t_params *pr)
{
	if (pr->type == 'x' || pr->type == 'p' || pr->type == 'u')
		ft_strcpy(base, "0123456789abcdef");
	else if (pr->type == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	else if (pr->type == 'o')
		ft_strcpy(base, "01234567");
	else
		ft_strcpy(base, "0123456789");
}

void				flags_int(va_list args, t_params *pr)
{
	unsigned int	nb;
	char			base[17];

	if (pr->type == 'd' || pr->type == 'i')
	{
		check_base(base, pr);
		nb = va_arg(args, unsigned int);
		if (!(pr->type == 'p'))
			nb = (unsigned int)nb;
		if (pr->precision == 0 && !nb)
			pr->str = ft_strdup("");
		else
			pr->str = ft_itoa(nb);
	}
}

void				flags_int_u(va_list args, t_params *pr)
{
	unsigned int	nb;
	char			base[17];
	check_base(base, pr);
	nb = va_arg(args, unsigned int);
	if (pr->type == 'u')
		nb = (unsigned int)nb;
	if (pr->precision == 0 && !nb)
		pr->str = ft_strdup("");
	else
		pr->str = ft_itoa_unsigned(nb);
}

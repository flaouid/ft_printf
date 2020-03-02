/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 13:18:22 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/02 15:49:26 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	parse_error(t_params *pr)
{
	if (pr->minus && pr->zero)
		pr->zero = 0;
	if (pr->plus && pr->space)
		pr->space = 0;
	if (pr->type == 'p')
		pr->hash = 1;
	if (pr->type == 'p' && pr->space)
		pr->space = 0;
	if (pr->type == 'p' && pr->plus)
		pr->plus = 0;
	if (pr->precision > 0 && (pr->var_type == INT || pr->var_type == INT_U))
		pr->zero = 0;
}

void	get_type_variable(t_params *pr)
{
	if (pr->type == 'd' || pr->type == 'i' || pr->type == 'u')
		pr->var_type = INT;
	else if (pr->type == 'p' || pr->type == 'x' ||
			pr->type == 'X' || pr->type == 'o')
		pr->var_type = INT_U;
	else if (pr->type == 's')
		pr->var_type = STR;
	else if (pr->type == 'c')
		pr->var_type = CHAR;
}

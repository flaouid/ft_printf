/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:58:05 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/08 13:26:40 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void			get_str(va_list args, t_params *pr)
{
	char		tmp[2];

	if (pr->type == 'u')
		flags_int_u(args, pr);
	else if (pr->type == 'x' || pr->type == 'X')
		flags_int_ll_x(args, pr);
	else if (pr->var_type == INT)
		flags_int(args, pr);
	else if (pr->var_type == STR)
		flags_str(args, pr);
	else if (pr->var_type == CHAR)
		flags_char(args, pr);
	else if (pr->var_type == INT_U)
		flags_int_ll(args, pr);
	else if (pr->type == '%')
	{
		tmp[0] = pr->type;
		tmp[1] = '\0';
		pr->str = ft_strdup(tmp);
	}
}

void			move_x(t_params *pr)
{
	pr->str[0] = '0';
	pr->str[1] = 'x';
}

void			modif_str(t_params *pr)
{
	if (pr->type != 'c' && pr->type != '%')
		parse_precision(pr);
	if (pr->type == 'd' || pr->type == 'i' ||
		pr->type == 'p' || pr->type == 'u')
		check_sign(pr);
	parse_precision(pr);
	parse_width(pr);
	check_hash(pr);
}

int				parse_arg(int fd, char **cpy, va_list args, int *write)
{
	t_params	*pr;
	int			ret;
	int			i;

	pr = (t_params*)ft_memalloc(sizeof(t_params));
	(*cpy)++;
	pr->precision = -1;
	check(cpy, pr, args);
	if (!pr->type)
	{
		(*cpy)--;
		return (0);
	}
	get_type_variable(pr);
	get_str(args, pr);
	parse_error(pr);
	if (!pr->char_null)
		modif_str(pr);
	i = 0;
	ret = print_arg(fd, pr, write, i);
	free(pr->str);
	free(pr);
	return (ret);
}

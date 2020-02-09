#include "../include/printf.h"


// envoie a la bonne fonction en fonction du type de variable

void	get_str(va_list args, t_params *pr)
{
	char tmp[2];

	if (pr->var_type == INT)
		flags_int(args, pr);
	else if (pr->var_type == STR)
		flags_str(args, pr);
	else if (pr->var_type == CHAR)
		flags_char(args, pr);
	else if (pr->var_type == INT_U)
		flags_int_ll(args, pr);
	if (pr->type == '%')
	{
		tmp[0] = pr->type;
		tmp[1] = '\0';
		pr->str = ft_strdup(tmp);
	}
}


// fonction spe pour decaler le flag avec les 0 devants


void	 move_x(t_params *pr)
{
	int i;

	i = -1;
	while (pr->str[++i])
	{
		if (pr->str[i] == 'x')
		{
			if (ft_strlen(pr->str) > 3)
			{
				pr->str[i] = '0';
				pr->str[1] = 'x';
			}
		}
		if (pr->str[i] != '0')
			break ;
	}
}


// modifier la string selon : precision, signe, width


void	modif_str(t_params *pr)
{
	if (pr->type != 'c' && pr->type != '%')
		parse_precision(pr);
	if (pr->type == 'd' || pr->type == 'i' || pr->type == 'p' || pr->type == 'u')
		check_sign(pr);
	parse_precision(pr);
	parse_width(pr);
	check_hash(pr);
	if (pr->hash && pr->width)
		move_x(pr);
}

// coeur de la fonction qui gere l'argument

int		parse_arg(int fd, char **cpy, va_list args, int *write)
{
	t_params *pr;
	int ret;

	pr = (t_params*)ft_memalloc(sizeof(t_params));
	(*cpy)++;
	check(cpy, pr, args);
	if (!pr->type)
	{
		free(pr);
		(*cpy)--;
		return (0);
	}
	get_type_variable(pr);
	get_str(args, pr);
	parse_error(pr);
	if (!pr->char_null)
		modif_str(pr);
	ret = print_arg(fd, pr, write);
	free(pr->str);
	free(pr);
	return (ret);
}

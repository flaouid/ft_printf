#include "../include/printf.h"

// Gere la largeur. Ajoute 0 ou ' ' a gauche ou a droite.

void	parse_width(t_params *pr)
{
	int		length;

	length = ft_strlen(pr->str);
	if (pr->width > length)
	{
		if (pr->minus)
		{
			add_str(&(pr->str), pr->zero > 0 ? '0' : ' ', pr->width - length, 0);
		}
		else
		{
			add_str(&(pr->str), pr->zero > 0 ? '0' : ' ', pr->width - length, 1);
		}

	}
}

// Gere la precision : cut si variable str et prec sont < , et ajoute des 0 si >

void	parse_precision(t_params *pr)
{
	char *str;

	if (pr->var_type == STR)
	{
		if (pr->precision < (int)ft_strlen(pr->str) && pr->precision > 0)
		{
			str = ft_substr(pr->str, 0, pr->precision);
			free(pr->str);
			pr->str = str;
		}
	}
	else if (pr->precision >= (int)ft_strlen(pr->str))
	{
		if (pr->str[0] == '+' || pr->str[0] == '-')
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str) + 1, 1);
		else
			add_str(&(pr->str), '0', pr->precision - ft_strlen(pr->str), 1);
	}
	if (pr->precision < 0 && pr->str[0] == '0')
		ft_strdel(pr->str);
}

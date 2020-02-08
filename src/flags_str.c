#include "../include/printf.h"

void	flags_str(va_list args, t_params *pr)
{
	char *temp;
	temp = va_arg(args, char *);
	if (pr->type == 's' && temp)
		pr->str = ft_strdup(temp);
	else if (pr->type == 's' && !temp)
		pr->str = ft_strdup("(null)");
	if (pr->precision < 0)
		ft_strdel(pr->str);
}

void	flags_char(va_list args, t_params *pr)
{
	char	*str;

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

void	flags_int_ll(va_list args, t_params *pr)
{
	unsigned long long nb;
	char	base[17];

	check_base(base, pr);
	nb = va_arg(args, unsigned long long);
	if (pr->type == 'p')
		nb = (unsigned long long int)nb;
	pr->str = ft_itoa_base_ll(nb, base);
}

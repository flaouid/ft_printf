#include "../include/printf.h"

/* Cette fonction recupere le nombre et le transforme en char*,
   dans la bonne base et avec les bonnes conversions.
*/

void		check_base(char base[17], t_params *pr)
{
	if	(pr->type == 'x' || pr->type == 'p' || pr->type == 'u')
		ft_strcpy(base, "0123456789abcdef");
	else if (pr->type == 'X')
		ft_strcpy(base,"0123456789ABCDEF");
	else if (pr->type == 'o')
		ft_strcpy(base, "01234567");
	else
		ft_strcpy(base, "0123456789");
}

void	get_str_u_nb(va_list args, t_params *pr)
{
	unsigned long long nb;
	char	base[17];

	check_base(base, pr);
	nb = va_arg(args, unsigned long long);
	if (pr->type == 'p')
		nb = (unsigned long int)nb;
	else
		nb = (unsigned int)nb;
	pr->str = ft_itoa(nb);
}


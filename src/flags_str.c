#include "../include/printf.h"

void	flags_str(va_list args, t_params *pr)
{
	char *tmp;

	if (pr->type == 's')
		pr->str = ft_strdup(va_arg(args, char*));
	if (pr->str == NULL)
		pr->str = ft_strdup("(null)");
	if (pr->precision < 0)
		ft_strdel(pr->str);
}

void	flags_char(va_list args, t_params *pr)
{
	char	*tmp;

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

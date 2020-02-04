#include "../include/printf.h"

// Gere les cas d'erreurs

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
	if (pr->precision != 0 && (pr->var_type == INT || pr->var_type == INT_U))
		pr->zero = 0;
}

// Recup type variable

void	get_type_variable(t_params *pr)
{
	if (pr->type == 'd' || pr->type == 'i')
		pr->var_type = INT;
	else if (pr->type == 'u' || pr->type == 'p' || pr->type == 'x' || pr->type == 'X')
		pr->var_type = INT_U;
	else if (pr->type == 's')
		pr->var_type = STR;
	else if (pr->type == 'c')
		pr->var_type = CHAR;
}

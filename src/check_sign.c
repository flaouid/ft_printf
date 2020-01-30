#include "../include/printf.h"

void	check_sign(t_params *pr)
{
	if (pr->plus && pr->str[0] != '-')
		add_str(&(pr->str), '+', 1, 1);
	if (pr->space && pr->str[0] != '-')
		add_str(&(pr->str), ' ', 1, 1);
}

void	check_hash(t_params *pr)
{
	if (pr->hash)
	{
		if (ft_strlen(pr->str) == 1 & pr->str[0] == '0' && pr->type != 'p')
			return ;
		if ((pr->type == 'x' || pr->type == 'X') && !pr->str[0])
			return ;
		if ((pr->type == 'o' && pr->str[0] == '0'))
			ft_strjoin("0", pr->str);
		else if (pr->type == 'X')
			ft_strjoin("0X", pr->str);
		else if ((pr->type == 'p' || pr->type == 'x'))
			ft_strjoin("0x", pr->str);
	}
}

#include "../include/printf.h"

// print l'argument, gere le cas du char 0, incremente le compteur de retour

void	print_arg(int fd, t_params *pr, int *print)
{
	int	i;
	char c;

	print = print + ft_strlen(pr->str);
	write(fd, pr->str, ft_strlen(pr->str));
	if (pr->char_null)
	{
		if (!pr->width)
			print = print + 1;
		else
		{
			if (pr->width && !pr->minus)
			{
				c = pr->zero ? '0' : ' ';
				i = 0;
				while (++i < pr->width)
					write(fd, &c, 0);
			}
			print = print + pr->width;
		}
		ft_putchar(0);
	}
}

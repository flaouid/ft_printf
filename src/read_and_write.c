#include "../include/printf.h"

void	ft_putnstr_fd(int fd, char *cpy, size_t *n, int *print)
{
	if (cpy)
	{
		write(fd, cpy - *n, *n);
		*print = *print + *n;
		*n = 0;
	}
}

int		write_again(int fd, char *cpy, va_list args, int *print)
{
	int		ret;
	size_t	n;

	n = 0;
	while (*cpy)
	{
		if (*cpy != '%')
			n++;
		else
		{
			if (n)
				ft_putnstr_fd(fd, cpy, &n, print);
			ret = parse_arg(fd, &cpy, args, print);
			if (ret == -1 || ret == 0)
				return (ret);
		}
		cpy++;
	}
	if (n)
		ft_putnstr_fd(fd, cpy, &n, print);
	return (0);
}

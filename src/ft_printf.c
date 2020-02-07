#include "../include/printf.h"

int			ft_vdprintf(int fd, const char *format, va_list args)
{
	char	*cpy;
	int		write;
	int		ret;

	cpy = (char*)format;
	write = 0;
	ret = write_again(fd, cpy, args, &write);
		return (ret == -1 ? ret : write);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			ret;

	va_start(args, format);
	ret = ft_vdprintf(fd, format, args);
	va_end(args);
	return (ret);
}

int			ft_vprintf(const char *format, va_list args)
{
	int			ret;

	ret = ft_vdprintf(1, format, args);
	return (ret);
}

int		ft_printf(const char *s, ...)
{
	va_list		args;
	int			ret;

	va_start(args, s);
	ret = ft_vdprintf(1, s, args);
	va_end(args);
	while (s[ret] != '\0')
		ret++;
	return (ret + 1);
}

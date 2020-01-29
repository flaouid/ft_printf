#include "../include/printf.h"

int		ft_printf(const char *s, ...)
{
	va_list		args;
	int			ret;

	va_start(args, s);
	//ret = ft_printf(1, s, args);
	va_end(args);
	return (ret);
}

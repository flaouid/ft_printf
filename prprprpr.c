/*int			i;
	t_struct	*data;
	va_list		arg;
	int			a;
	a = 0;
	i = 0;
	va_start(arg, str);
	data = (t_struct *)malloc(sizeof(t_struct));
	while (str[i])
	{
		if (str[i] && str[i] == '%')
		{
			i++;
			ft_struct(str, arg, &i, data);
			a += select_type(data, arg);
		}
		else
			a += ft_putchar_fd_return(str[i++], 1);
	}
	free(data);
	va_end(arg);
	return (a);

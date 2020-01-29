#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <inttypes.h>

# include "../libft/libft.h"
# include "../include/printf.h"

# define CHAR 1
# define INT 2
# define STR 3
# define INT_U 4
# define JOIN_END 1
# define JOIN_START 2
# define STAR_PREC 1
# define STAR_WIDTH 2

typedef struct s_params
{
	char	*str;
	int		precision;
	int		width;
	int		var_type;
	char	type;
	int		star;
	int		char_null :2;
	int		hash :2;
	int		zero :2;
	int		space :2;
	int		plus :2;
	int		minus :2;
}			t_params;

void			flags_str(va_list args, t_params *pr);
void			flags_char(va_list args, t_params *pr);
void			ft_strjoin_free(char *add, char **src, int type);
static void		check_flags(char c, t_params *pr);
static void		flags_width_prec(char **cpy, t_params *pr, va_list args);
void			check_star(va_list args, t_params *pr, int i);
void			check(char **cpy, t_params *pr, va_list args);
static void		check_base(char base[17], t_params *pr);
void			add_str(char **str, char type, int number, int start);
void			parse_error(t_params *pr);
void			get_type_variable(t_params *pr);

#endif

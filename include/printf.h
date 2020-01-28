#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <inttypes.h>

# include "../libft/libft.h"
# include "../includes/printf.h"

# define CHAR 1
# define INT 2
# define STR 3
# define INT_U 4
# define JOIN_END 1
# define JOIN_START 2
# define STAR_PREC 1
# define STAR_WIDTH 2

typedef struct t_params
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
}			s_params;

void	flags_str(va_list args, t_params *pr);
void	flags_char(va_list args, t_params *pr);
void	strjoin_free(char *add, char **src, int type);

#endif

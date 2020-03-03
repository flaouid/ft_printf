/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaouid <laouid.ferdaous@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 12:53:38 by flaouid           #+#    #+#             */
/*   Updated: 2020/03/03 13:58:50 by flaouid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct	s_params
{
	char		*str;
	int			precision;
	int			width;
	int			var_type;
	char		type;
	int			star;
	int			char_null :2;
	int			hash :2;
	int			zero :2;
	int			space :2;
	int			plus :2;
	int			minus :2;
}				t_params;

void			add_str(char **str, char type, int number, int start);
void			flags_str(va_list args, t_params *pr);
void			flags_char(va_list args, t_params *pr);
void			flags_int(va_list args, t_params *pr);
void			flags_int_ll(va_list args, t_params *pr);
void			flags_int_ll_x(va_list args, t_params *pr);
void			flags_int_u(va_list args, t_params *pr);
void			flags_width_prec(char **cpy, t_params *pr, va_list args);
void			ft_strjoin_free(char *add, char **src, int type);
int				ft_printf(const char *s, ...);
int				ft_vprintf(const char *format, va_list args);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list args);
void			ft_putnstr_fd(int fd, char *cpy, size_t *n, int *print);
void			check_flags(char c, t_params *pr);
void			check_sign(t_params *pr);
void			check_star(va_list args, t_params *pr, int i);
void			check(char **cpy, t_params *pr, va_list args);
void			check_base(char base[17], t_params *pr);
void			check_hash(t_params *pr);
void			get_type_variable(t_params *pr);
void			get_str(va_list args, t_params *pr);
void			move_x(t_params *pr);
void			modif_str(t_params *pr);
int				parse_arg(int fd, char **cpy, va_list args, int *write);
void			parse_width(t_params *pr);
void			parse_precision(t_params *pr);
void			parse_error(t_params *pr);
int				print_arg(int fd, t_params *pr, int *print);
void			strjoin_free(char *add, char **src, int type);
int				write_again(int fd, char *cpy, va_list args, int *print);

#endif

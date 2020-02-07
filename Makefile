NAME = libftprintf.a

SRC = ./src/check_flags.c\
	  ./src/check_arg.c\
	  ./src/check_sign.c\
	  ./src/flags_str.c\
	  ./src/print_arg.c\
	  ./src/read_and_write.c\
	  ./src/check_width_prec.c\
	  ./src/ft_printf.c\
	  ./src/get_nbr_base.c\
	  ./src/printf_utils.c\
	  ./src/to_convert.c\
	  ./libft/ft_atoi.c\
	  ./libft/ft_bzero.c\
	  ./libft/ft_ischarset.c\
	  ./libft/ft_memalloc.c\
	  ./libft/ft_memset.c\
	  ./libft/ft_bzero.c\
	  ./libft/ft_strcpy.c\
	  ./libft/ft_strdup.c\
	  ./libft/ft_strjoin.c\
	  ./libft/ft_strcpy.c\
	  ./libft/ft_strcat.c\
	  ./libft/ft_isdigit.c\
	  ./libft/ft_putchar.c\
	  ./libft/ft_strdel.c\
	  ./libft/ft_strlen.c\
	  ./libft/ft_substr.c\
	  ./libft/ft_itoa_base.c\
	  ./libft/ft_putstr.c\
	  ./libft/ft_itoa.c

OBJ = $(SRC:.c=.o)
LIB_OBJ = ./libft/*.o
INCLUDES = ../include/printf.h
LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

.c.o : $(SRC)
	@(gcc -c $(FLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) $^

ex : $(NAME)
	@(gcc -Wall -Wextra -Werror -g3 -fsanitize=address main.c libftprintf.a)
	@(./a.out)

clean :
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)

re : fclean all

NAME		= philo_bonus
SRCS_PATH	= ./srcs

FILES		= philosophers_bonus \
			  valid_args \
			  aux_funcs/ft_atol \
			  aux_funcs/ft_is_digit \
			  aux_funcs/ft_is_sign \
			  aux_funcs/ft_is_space \
			  aux_funcs/is_number \
			  aux_funcs/print_error

SRCS		= $(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(SRCS_PATH)/, $(addsuffix .o, $(FILES)))
CFLAGS		= -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

%.o : %.c
	cc $(CFLAGS) -I ./includes -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

NAME		= philo_bonus
SRCS_PATH	= ./srcs

FILES		= philosophers_bonus \
			  valid_args_bonus \
			  init_bonus \
			  aux_funcs_bonus/ft_atol_bonus \
			  aux_funcs_bonus/ft_is_digit_bonus \
			  aux_funcs_bonus/ft_is_sign_bonus \
			  aux_funcs_bonus/ft_is_space_bonus \
			  aux_funcs_bonus/is_number_bonus \
			  aux_funcs_bonus/print_error_bonus \
			  aux_funcs_bonus/time_bonus \
			  aux_funcs_bonus/ft_strcmp_bonus

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

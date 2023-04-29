NAME		= philo
SRCS_PATH	= ./srcs

FILES		= philosophers
SRCS		= $(addprefix $(SRCS_PATH)/, $(addsuffix .c, $(FILES)))
OBJS		= $(addprefix $(SRCS_PATH)/, $(addsuffix .o, $(FILES)))
CFLAGS		= -g3 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	cc $(FLAGS) -I ./includes -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

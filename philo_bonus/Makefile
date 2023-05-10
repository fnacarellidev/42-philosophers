NAME		= philo_bonus
SRCS_PATH	= ./srcs

FILES		= philosophers_bonus

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

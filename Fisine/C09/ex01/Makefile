NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INC = includes

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

clean : 
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re

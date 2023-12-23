NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft

INC = ft_printf.h

CC = cc
CFLAGS = -c -Wall -Wextra -Werror -MMD -MP
RM = rm -rf
LIB_DIR = ./libft

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR)
    cp $(LIB_DIR)/libft.a $@
	ar -rcs $@ $^

clean : 
	$(RM) $(OBJS)
	rm -f
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re 
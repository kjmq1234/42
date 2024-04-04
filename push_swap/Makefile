NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	init_data.c \
deque_utils.c \
push_swap_method1.c push_swap_method2.c push_swap_method3.c test_main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	@clean
re: fclean all
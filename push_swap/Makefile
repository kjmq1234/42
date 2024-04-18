NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft.a
LIBFT_DIR = libft

SRCS = init_data.c \
	   deque_utils.c \
	   hard_sort.c \
	   main.c \
	   push_swap_method1.c \
	   push_swap_method2.c \
	   push_swap_method3.c \
	   parsing_utils1.c \
	   parsing_utils2.c \
	   sort_utils.c \
	   sort.c \
	   utils.c \
	   hard_sort_utils4.c \
	   hard_sort_utils5.c \
	

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(LIBFT_DIR)/$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

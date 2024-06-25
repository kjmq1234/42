NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra


SRCS = main.c \
	   utils.c \
		error_handle.c \
		init_data.c \
		print_mutex.c \
		handle_thread.c \
		philo_actions.c \
		free_resource.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

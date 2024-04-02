NAME = so_long
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFTDIR = ./libft

SRCS = main.c init_data.c utils.c map_valid.c map_utils.c map_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

makeprintf:
	make -C ./libftprintf
	cp ./libftprintf/libftprintf.a .
	mv libftprintf.a $(NAME)

$(NAME): makelibft makeprintf $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus:

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all

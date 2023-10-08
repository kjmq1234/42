NAME = bsq

SRCS = vect_read.c ft_split.c main.c make_int_arr.c errfunc.c dp.c check_valid.c
OBJS = vect_read.o ft_split.o main.o make_int_arr.o errfunc.o dp.o check_valid.o

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f


all : $(NAME)

$.o : %.c
	$(CC) $(CFLAGS) -c $< $@ -I ft.h

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS) 
fclean : clean
	$(RM) $(NAME) 
re : fclean all 
.PHONY : all clean fclean re 

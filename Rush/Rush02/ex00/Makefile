

NAME = Rush-02

SRCS = main.c parsing.c parsing_tool2.c parsing_tool.c printer.c struct.c valid_check.c
OBJS = main.o parsing.o parsing_tool2.o parsing_tool.o printer.o struct.o valid_check.o
INC = rush02.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


all : $(NAME) 

$.o : %.c
	$(CC) $(CFLAGS) -c $< $@ -I $(INC) 

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re

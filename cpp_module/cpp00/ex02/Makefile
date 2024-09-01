CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = The_Job_Of_Your_Dreams

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re
CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp main.cpp phonebook.cpp

OBJS = $(SRCS:.cpp=.o)

TARGET = phonebook

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
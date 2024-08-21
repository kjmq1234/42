CC = g++

CFLAGS = -Wall -Wextra -Werror

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
NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp
INCLUDES = Fixed.hpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(NAME)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

NAME = harl

CC = c++
CFLAGS =	-Wall -Wextra -Werror \
			-std=c++98

OBJ_DIR = obj/
FILES = main Harl
SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
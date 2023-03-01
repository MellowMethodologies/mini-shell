SRC_DIR = srcs
OBJ_DIR = objs
SRCS =	main.c
OBJS := $(SRCS:%.c=$(OBJ_DIR)/%.o)
CC  = cc
CFLAGS = -Wall -Wextra -Werror
NAME = shell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = index.c list_helpers.c list.c main.c mini_sort.c operations2.c operations3.c operations.c parsing.c radix_sort.c utils.c validation_and_create_arr.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

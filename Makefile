NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O2

SRC_DIR = ./

SO_LONG_FILES = so_long.c

OBJ_DIR = obj/

SO_LONG_OBJ_FILES = $(patsubst %.c,%.o,$(SO_LONG_FILES))

SO_LONG_OBJ = $(addprefix $(OBJ_DIR), $(SO_LONG_OBJ_FILES))

HEADER = so_long.h

MLX_DIR = mlx

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ_DIR) $(SO_LONG_OBJ)
	@make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(SO_LONG_OBJ) mlx/libmlx.a -framework OpenGL -framework AppKit

$(OBJ_DIR): 
			mkdir $(OBJ_DIR)

$(SO_LONG_OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c -I $(HEADER) -o $@ $<

clean:
	# @make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all


NAME = so_long

CC = gcc

CFLAGS =  -O2

SRC_DIR = ./src/

SO_LONG_FILES = so_long.c parse_map.c valid_map.c engine_map.c animation_obj.c key_hook.c live_render.c

OBJ_DIR = obj/

SO_LONG_OBJ_FILES = $(patsubst %.c,%.o,$(SO_LONG_FILES))

SO_LONG_OBJ = $(addprefix $(OBJ_DIR), $(SO_LONG_OBJ_FILES))

HEADER = src/so_long.h

MLX_DIR = mlx

GNL_DIR = gnl_l

LIBFT_DIR = libft

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ_DIR) $(SO_LONG_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@make -C $(GNL_DIR)
	$(CC) -o $(NAME) $(SO_LONG_OBJ) libft/libft.a gnl_l/gnl.a mlx/libmlx.a -framework OpenGL -framework AppKit

$(OBJ_DIR): 
			mkdir $(OBJ_DIR)

$(SO_LONG_OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
			$(CC) $(CFLAGS) -c -I $(HEADER) -o $@ $<

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@rm -f $(NAME)

re: fclean all

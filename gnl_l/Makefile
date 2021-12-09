NAME = gnl.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O2

SRC_DIR = ./

GNL_FILES = get_next_line.c get_next_line_utils.c

GNL_OBJ_FILES = $(patsubst %.c,%.o,$(GNL_FILES))

GNL_OBJ = $(addprefix obj/, $(GNL_OBJ_FILES))

HEADER = get_next_line.h

.PHONY: all clean fclean re

all: obj/ $(NAME) 

obj/ :
	@mkdir obj/

$(NAME): 	 $(GNL_OBJ)
		ar rcs $(NAME) $?

obj/%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c  -o $@ $<

clean:
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

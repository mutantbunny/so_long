CC = cc
CC_FLAGS = -Wall -Wextra -g3 -O3
REMOVE = rm -f

LIBFT_DIR = ./lib/libft

LIBMLX_DIR = ./lib/mlx
HEADER_DIR = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
ASSET_DIR = ./asset

LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx.a
HEADER_FILES = $(addprefix $(HEADER_DIR), so_long.h)
SRC_FILES = $(addprefix $(SRC_DIR), hooks.c init.c map.c movement.c render.c so_long.c validation.c)
OBJ_FILES = $($(SRC_FILES:.c=.o):$(SRC_DIR)=$(OBJ_DIR))
NAME = $(BUILD_DIR)/so_long

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBMLX_FILE) $(LIBFT_FILE)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) $(LIBMLX_FILE) $(LIBFT_FILE) -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) $(LIBMLX_FILE) $(LIBFT_FILE) -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	$(RM) $(OBJ_FILES)

fclean:
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) fclean
	$(RM) $(OBJ_FILES)
	$(RM) $(NAME)

norm:
	norminette $(SRC_FILES) $(HEADER_FILES)

re:	fclean all

.PHONY: all clean fclean norm re

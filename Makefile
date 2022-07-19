CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf

LIBFT_DIR = ./lib/libft
LIBMLX_DIR = ./lib/libmlx
FT_PRINTF_DIR = ./lib/ft_printf
HEADER_DIR = ./include
SRC_DIR = ./src
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj
ASSET_DIR = ./asset

LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx.a
FT_PRINTF_FILE = $(FT_PRINTF_DIR)/libftprintf.a
HEADER_FILES = $(addprefix $(HEADER_DIR)/, so_long.h)
SRC_FILES = $(addprefix $(SRC_DIR)/, hooks.c init.c map.c movement.c render.c so_long.c validation.c)
OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC_FILES:.c=.o))
INCLUDE_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR) -I$(FT_PRINTF_DIR)
LIB_FLAGS = -L$(LIBMLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft
NAME = $(BUILD_DIR)/so_long

all: $(NAME)

$(NAME): $(LIBMLX_FILE) $(LIBFT_FILE) $(FT_PRINTF_FILE) $(OBJ_FILES) $(HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(LIBMLX_FILE):
	make -C $(LIBMLX_DIR)

$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

$(FT_PRINTF_FILE):
	make -C $(FT_PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< $(INCLUDE_FLAGS) -c -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean
	make -C $(FT_PRINTF_DIR) fclean
	$(RM) $(BUILD_DIR)

norm:
	norminette $(SRC_FILES) $(HEADER_FILES)

re:	fclean all

.PHONY: all clean fclean norm re

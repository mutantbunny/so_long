CC = cc
CC_FLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf

LIBFT_DIR = ./lib/libft
LIBMLX_DIR = ./lib/libmlx
BUILD_DIR = ./build
ASSET_DIR = ./asset
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBMLX_FILE = $(LIBMLX_DIR)/libmlx.a

HEADER_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = $(BUILD_DIR)/obj
HEADER_FILES = $(addprefix $(HEADER_DIR)/, so_long.h)
SRC_FILES = $(addprefix $(SRC_DIR)/, hooks.c init.c map.c movement.c render.c so_long.c validation.c)
OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC_FILES:.c=.o))

HEADER_BONUS_DIR = ./include/bonus
SRC_BONUS_DIR = ./src/bonus
OBJ_BONUS_DIR = $(BUILD_DIR)/obj/bonus
HEADER_BONUS_FILES = $(addprefix $(HEADER_BONUS_DIR)/, so_long_bonus.h)
SRC_BONUS_FILES = $(addprefix $(SRC_BONUS_DIR)/, enemy.c frames.c hooks.c init.c load_tiles.c map.c move_hero.c move_enemies.c render.c so_long.c text.c validation.c)
OBJ_BONUS_FILES = $(subst $(SRC_BONUS_DIR), $(OBJ_BONUS_DIR), $(SRC_BONUS_FILES:.c=.o))


INCLUDE_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
INCLUDE_BONUS_FLAGS = -I$(HEADER_BONUS_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
LIB_FLAGS = -L$(LIBMLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -L$(LIBFT_DIR) -lft
LIB_BONUS_FLAGS = -L$(LIBMLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -L$(LIBFT_DIR) -lft -lm

NAME = $(BUILD_DIR)/so_long
NAME_BONUS = $(BUILD_DIR)/so_long_bonus

all: $(NAME)

$(NAME): $(LIBMLX_FILE) $(LIBFT_FILE) $(OBJ_FILES) $(HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(LIBMLX_FILE):
	make -C $(LIBMLX_DIR)

$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBMLX_FILE) $(LIBFT_FILE) $(OBJ_BONUS_FILES) $(HEADER_BONUS_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(OBJ_BONUS_FILES) $(INCLUDE_FLAGS) $(LIB_BONUS_FLAGS) -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(HEADER_BONUS_FILES)
	mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(CC_FLAGS) $< $(INCLUDE_BONUS_FLAGS) -c -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< $(INCLUDE_FLAGS) -c -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) clean
	$(RM) $(BUILD_DIR)

norm:
	norminette $(SRC_FILES) $(HEADER_FILES) $(SRC_BONUS_FILES) $(HEADER_BONUS_FILES)


re:	fclean all

.PHONY: all bonus clean fclean norm re

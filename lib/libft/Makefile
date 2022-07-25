CC = cc
AR = ar rcs
REMOVE = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c \
            ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c \
            ft_substr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c \
            ft_memset.c ft_strdup.c ft_strlcat.c ft_strmapi.c \
            ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c ft_itoa.c \
            ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c \
            ft_putnbr_fd.c ft_split.c ft_striteri.c \
            ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
            dec_utils.c ft_printf.c gen_parsers.c \
            hex_utils.c int_parsers.c main_parsers.c ft_printf_utils.c

BONUS_SRC_FILES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
                  ft_lstclear_bonus.c ft_lstdelone_bonus.c \
                  ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
                  ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)
HEADER_FILES = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) $(NAME) $(OBJ_FILES)

bonus: $(NAME:.a=_bonus.a)

$(NAME:.a=_bonus.a): $(OBJ_FILES) $(BONUS_OBJ_FILES)
	$(AR) $(NAME:.a=_bonus.a) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	cp $(NAME:.a=_bonus.a) $(NAME)

%_bonus.o: %_bonus.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	$(REMOVE) $(NAME) $(NAME:.a=_bonus.a)

re:	fclean all

norm:
	norminette

.PHONY: all bonus clean fclean norm re
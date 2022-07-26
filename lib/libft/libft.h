/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 02:07:51 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 15:53:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

// ctype.h
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);

// string.h
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);

// strings.h (deprecated)
void			ft_bzero(void *s, size_t n);

// bsd/string.h
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);

// type.h
int				ft_tolower(int c);
int				ft_toupper(int c);

// stdlib.h
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);

// Additional functions
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);

// Bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			ft_lstadd_back(t_list **lst, t_list *new_lst);
void			ft_lstadd_front(t_list **lst, t_list *new_lst);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);

// ft_printf
# define UPPERCASE 1U
# define LOWERCASE 2U
# define PAD_WITH_ZEROS 4U
# define HEX_PREFIX 8U
# define MINUS_PREFIX 16U
# define PLUS_PREFIX 32U
# define SPACE_PREFIX 64U
# define JUSTIFY_LEFT 128U
# define PRECISION_SET 256U

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_format
{
	int				width;
	int				precision;
	unsigned int	flags;
}	t_format;

// main_parsers.c
unsigned int	parse_flags(const char **str);
int				parse_width(const char **str);
int				parse_precision(const char **str, t_format *format);
int				parse_specifier(const char *str, t_format *format,
					va_list args);
int				parse_format(const char **str, va_list args);

// gen_parsers.c
int				parse_char(va_list args, t_format *format);
int				parse_pointer(va_list args, t_format *format);
int				parse_str(va_list args, t_format *format);

// int_parsers.c
int				parse_int(va_list args, t_format *format);
int				parse_uint(va_list args, t_format *format);
int				parse_hex_upper(va_list args, t_format *format);
int				parse_hex_lower(va_list args, t_format *format);

// dec_utils.c
int				write_dec_left_justified(char *s, int len,
					t_format *format, int num_zeros);
int				write_dec_right_justified(char *s, int len,
					t_format *format, int num_zeros);
int				write_dec_padded(char *s, int len, t_format *format);
int				putnbr_dec_int(int nbr, t_format *format);
int				putnbr_dec_uint(unsigned int nbr, t_format *format);

// hex_utils.c
int				write_hex_left_justified(char *s, int len,
					t_format *format, int num_zeros);
int				write_hex_right_justified(char *s, int len,
					t_format *format, int num_zeros);
int				write_hex_padded(char *s, int len, t_format *format);
char			get_hex_digit(unsigned int digit, t_format *format);
int				putnbr_hex_uint(unsigned long nbr, t_format *format);

// ft_printf_utils.c
int				write_repeated(char ch, int num_ch);
int				min(int a, int b);
int				max(int a, int b);

// ft_printf.c
int				ft_printf(const char *str, ...);

#endif
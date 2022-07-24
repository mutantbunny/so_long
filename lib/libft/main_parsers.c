/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:41 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 18:17:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	parse_flags(const char **str)
{
	unsigned int	flags;

	flags = 0;
	while (**str)
	{
		if (**str == '0')
			flags |= PAD_WITH_ZEROS;
		else if (**str == ' ')
			flags |= SPACE_PREFIX;
		else if (**str == '+')
			flags |= PLUS_PREFIX;
		else if (**str == '-')
			flags |= JUSTIFY_LEFT;
		else if (**str == '#')
			flags |= HEX_PREFIX;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

int	parse_width(const char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		(*str)++;
	}
	return (width);
}

int	parse_precision(const char **str, t_format *format)
{
	int	precision;

	if (**str != '.')
		return (0);
	(*str)++;
	precision = 0;
	while (ft_isdigit(**str))
	{
		precision = precision * 10 + (**str - '0');
		(*str)++;
	}
	format->flags |= PRECISION_SET;
	return (precision);
}

int	parse_specifier(const char *str, t_format *format, va_list args)
{
	if (*str == '\0')
		return (0);
	else if (*str == 'c')
		return (parse_char(args, format));
	else if (*str == 's')
		return (parse_str(args, format));
	else if (*str == 'p')
		return (parse_pointer(args, format));
	else if (*str == 'd' || *str == 'i')
		return (parse_int(args, format));
	else if (*str == 'u')
		return (parse_uint(args, format));
	else if (*str == 'x')
		return (parse_hex_lower(args, format));
	else if (*str == 'X')
		return (parse_hex_upper(args, format));
	else
	{
		write(1, str, 1);
		return (1);
	}
}

int	parse_format(const char **str, va_list args)
{
	t_format	format;

	format.flags = parse_flags(str);
	format.width = parse_width(str);
	format.precision = parse_precision(str, &format);
	return (parse_specifier((*str)++, &format, args));
}

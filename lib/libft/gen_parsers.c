/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_parsers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 02:45:21 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 18:17:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parse_char(va_list args, t_format *format)
{
	char	ch;
	int		copied;

	ch = (char)va_arg(args, int);
	copied = 0;
	if (format->flags & JUSTIFY_LEFT)
	{
		write(1, &ch, 1);
		copied += write_repeated(' ', format->width - 1) + 1;
	}
	else
	{
		copied += write_repeated(' ', format->width - 1) + 1;
		write(1, &ch, 1);
	}
	return (copied);
}

int	parse_pointer(va_list args, t_format *format)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		if (format->flags & JUSTIFY_LEFT)
		{
			write(1, "(nil)", 5);
			write_repeated(' ', format->width - 5);
		}
		else
		{
			write_repeated(' ', format->width - 5);
			write(1, "(nil)", 5);
		}
		return (max(5, format->width));
	}
	format->flags = (format->flags & JUSTIFY_LEFT) | HEX_PREFIX | LOWERCASE;
	return (putnbr_hex_uint((unsigned long)ptr, format));
}

int	parse_str(va_list args, t_format *format)
{
	int		copied;
	int		len;
	char	*arg;

	arg = va_arg(args, char *);
	copied = 0;
	if (arg == NULL)
	{
		if (!(format->flags & PRECISION_SET) || format->precision >= 6)
			len = 6;
		else
			len = 0;
		arg = "(null)";
	}
	else if (format->flags & PRECISION_SET)
		len = min(ft_strlen(arg), format->precision);
	else
		len = ft_strlen(arg);
	if (!(format->flags & JUSTIFY_LEFT))
		copied += write_repeated(' ', format->width - len);
	copied += write(1, arg, len);
	if ((format->flags & JUSTIFY_LEFT))
		copied += write_repeated(' ', format->width - len);
	return (copied);
}

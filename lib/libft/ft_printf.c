/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:41 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 18:17:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		copied;

	if (str == NULL)
		return (-1);
	len = 0;
	copied = 0;
	va_start(args, str);
	while (str[len] != '\0')
	{
		if (str[len++] != '%')
			continue ;
		write(1, str, --len);
		if (str[len + 1] == '\0')
			return (-1);
		str += (len + 1);
		copied += (len + parse_format(&str, args));
		if (str == NULL)
			return (-1);
		len = 0;
	}
	write(1, str, len);
	va_end(args);
	return (copied + len);
}

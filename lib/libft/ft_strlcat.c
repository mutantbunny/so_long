/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:25:20 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/13 19:58:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	const char	*dst_start;
	size_t		dst_length;

	src_start = src;
	dst_start = dst;
	while (size != 0 && *dst != '\0')
	{
		dst++;
		size--;
	}
	dst_length = dst - dst_start;
	if (size == 0)
		return (ft_strlen(src) + dst_length);
	while (*src != '\0')
	{
		if (size != 1)
		{
			*dst++ = *src;
			size--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_length + src - src_start);
}

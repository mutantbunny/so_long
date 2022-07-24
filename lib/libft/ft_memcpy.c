/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 02:41:31 by coelho            #+#    #+#             */
/*   Updated: 2022/04/18 20:06:34 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (src == NULL && dest == NULL && n != 0)
		return (dest);
	while (n-- != 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

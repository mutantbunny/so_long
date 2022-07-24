/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:52 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/20 15:00:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*allocated;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb != total_size / size)
		return (NULL);
	allocated = malloc(total_size);
	if (allocated == NULL)
		return (NULL);
	return (ft_memset(allocated, 0, total_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:07:57 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/07 11:50:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_found;

	last_found = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_found = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last_found);
}

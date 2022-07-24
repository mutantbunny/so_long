/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:45:57 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/13 21:04:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*copy;

	len_s = ft_strlen(s) + 1;
	copy = malloc(len_s * sizeof(char));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, len_s);
	return (copy);
}

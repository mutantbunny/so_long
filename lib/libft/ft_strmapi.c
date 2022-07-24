/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:38:52 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/20 14:51:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	position;

	if (s == NULL || f == NULL)
		return (NULL);
	position = 0;
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (*s != '\0')
	{
		result[position] = f(position, *s++);
		position++;
	}
	result[position] = '\0';
	return (result);
}

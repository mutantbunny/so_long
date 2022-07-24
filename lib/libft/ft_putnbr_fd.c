/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:08:00 by gmachado          #+#    #+#             */
/*   Updated: 2022/04/18 20:10:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#define MAX_CHARS 11
#define MAX_DIVIDER 1000000000

void	ft_putnbr_fd(int n, int fd)
{
	int		divider;
	char	digit;

	if (fd < 0)
		return ;
	divider = MAX_DIVIDER;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		divider = -divider;
	}
	while (divider != 0 && n / divider == 0)
		divider /= 10;
	while (divider != 0)
	{
		digit = '0' + (char)(n / divider);
		write(fd, &digit, 1);
		n %= divider;
		divider /= 10;
	}
}

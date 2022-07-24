/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 04:24:34 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 02:50:07 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	validate_shape(t_config *conf)
{
	int	x;
	int	y;

	x = 0;
	while (conf->map[0][x] != '\0')
		x++;
	if (x < 3)
		return (1);
	conf->map_width = x;
	y = 1;
	while (conf->map[y] != NULL)
	{
		x = 0;
		while (conf->map[y][x] != '\0')
			x++;
		if (x != conf->map_width)
			return (1);
		y++;
	}
	if (y < 3 || (x == 4 && y < 4) || (x == 3 && y < 5))
		return (1);
	conf->map_height = y;
	return (0);
}

/* Minimum map sizes
111    1111    11111
1P1    1PC1    1PCE1
1C1    1E 1    11111
1E1    1111
111
*/

int	validate_tile(t_config *conf, int x, int y, int start_count)
{
	char	tile;

	tile = conf->map[y][x];
	if (tile == START && start_count)
		conf->map[y][x] = EMPTY;
	return (tile == EMPTY
		|| tile == WALL
		|| tile == COIN
		|| tile == EXIT
		|| tile == START
		|| tile == ENEMY);
}

int	validate_tiles(t_config *conf)
{
	int	x;
	int	y;
	int	start_count;
	int	coin_count;
	int	exit_count;

	start_count = 0;
	coin_count = 0;
	exit_count = 0;
	y = 0;
	while (++y < conf->map_height - 1)
	{
		x = 0;
		while (++x < conf->map_width - 1)
		{
			if (!validate_tile(conf, x, y, start_count))
				return (ERR_CHAR);
			start_count += (conf->map[y][x] == START);
			coin_count += (conf->map[y][x] == COIN);
			exit_count += (conf->map[y][x] == EXIT);
		}
	}
	if ((start_count == 0 || coin_count == 0 || exit_count == 0))
		return (ERR_NUM);
	return (0);
}

int	validate_walls(t_config *conf)
{
	int	x;
	int	y;

	x = 0;
	while (x < conf->map_width)
	{
		if (conf->map[0][x] != WALL
			|| conf->map[conf->map_height - 1][x] != WALL)
			return (1);
		x++;
	}
	y = 1;
	while (y < conf->map_height - 1)
	{
		if (conf->map[y][0] != WALL
			|| conf->map[y][conf->map_width - 1] != WALL)
			return (1);
		y++;
	}
	return (0);
}

int	validate_map(t_config *conf)
{
	int	err;

	if (conf->map == NULL || *(conf->map) == NULL)
		return (ERR_OPEN);
	if (validate_shape(conf))
		return (ERR_SHAPE);
	if (validate_walls(conf))
		return (ERR_WALL);
	err = validate_tiles(conf);
	if (err)
		return (err);
	return (0);
}

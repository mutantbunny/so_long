/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/19 23:38:30 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	update_status(t_config *conf, int x, int y, char tile)
{
	mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->scr.img, 0, 0);
	if (tile == COIN)
	{
		conf->map[y][x] = EMPTY;
		conf->num_coins--;
	}
	else if (tile == EXIT)
	{
		if (conf->num_coins == 0)
		{
			ft_printf("Number of moves: %i\n", conf->num_moves);
			exit_program(conf);
		}
	}
}

void	move_up(void *param)
{
	char		tile;
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	tile = conf->map[y - 1][x];
	if (tile != WALL)
	{
		render_tile(conf, x, y, get_tile(conf, conf->map[y][x]));
		conf->hero.y--;
		conf->num_moves++;
	}
	draw_hero_up(conf, x, conf->hero.y);
	update_status(conf, x, y - 1, tile);
}

void	move_down(void *param)
{
	char		tile;
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	tile = conf->map[y + 1][x];
	if (tile != WALL)
	{
		render_tile(conf, x, y, get_tile(conf, conf->map[y][x]));
		conf->hero.y++;
		conf->num_moves++;
	}
	draw_hero_down(conf, x, conf->hero.y);
	update_status(conf, x, y + 1, tile);
}

void	move_left(void *param)
{
	char		tile;
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	tile = conf->map[y][x - 1];
	if (tile != WALL)
	{
		render_tile(conf, x, y, get_tile(conf, conf->map[y][x]));
		conf->hero.x--;
		conf->num_moves++;
	}
	draw_hero_left(conf, conf->hero.x, y);
	update_status(conf, x - 1, y, tile);
}

void	move_right(void *param)
{
	char		tile;
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	tile = conf->map[y][x + 1];
	if (tile != WALL)
	{
		render_tile(conf, x, y, get_tile(conf, conf->map[y][x]));
		conf->hero.x++;
		conf->num_moves++;
	}
	draw_hero_right(conf, conf->hero.x, y);
	update_status(conf, x + 1, y, tile);
}

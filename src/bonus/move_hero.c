/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 11:23:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	update_status(t_config *conf, int x, int y, int direction)
{
	char	tile;

	tile = conf->map[y][x];
	if (tile == COIN)
	{
		conf->map[y][x] = EMPTY;
		conf->num_coins--;
	}
	render_tile(conf, x, y, get_bg_tile(conf, tile));
	if (direction == UP)
		render_tile(conf, x, y, &(conf->hero.frames->up));
	else if (direction == DOWN)
		render_tile(conf, x, y, &(conf->hero.frames->down));
	else if (direction == LEFT)
		render_tile(conf, x, y, &(conf->hero.frames->left));
	else if (direction == RIGHT)
		render_tile(conf, x, y, &(conf->hero.frames->right));
	mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->scr.img, 0, 0);
	if (tile == EXIT)
	{
		if (conf->num_coins == 0)
			exit_program(conf);
	}
}

void	move_up(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y - 1][x] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.y--;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, x, conf->hero.y, UP);
}

void	move_down(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y + 1][x] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.y++;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, x, conf->hero.y, DOWN);
}

void	move_left(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y][x - 1] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.x--;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, conf->hero.x, y, LEFT);
}

void	move_right(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y][x + 1] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.x++;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, conf->hero.x, y, RIGHT);
}

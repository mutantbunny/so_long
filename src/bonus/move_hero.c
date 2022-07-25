/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:22 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 02:50:23 by gmachado         ###   ########.fr       */
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
	if (tile == EXIT && conf->num_coins == 0)
	{
		ft_printf("You exited the map after %i moves!\n", conf-> num_moves);
		exit_program(conf);
	}
	if (conf->state == HERO_TURN)
		conf->state = ENEMY_TURN;
}

void	move_hero_up(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y - 1][x] == ENEMY || conf->map[y - 1][x] == C_N_E
		|| conf->map[y - 1][x] == X_N_E)
	{
		conf->state = HERO_LOSE;
		return ;
	}
	if (conf->map[y - 1][x] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.y--;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, x, conf->hero.y, UP);
}

void	move_hero_down(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y + 1][x] == ENEMY || conf->map[y + 1][x] == C_N_E
		|| conf->map[y + 1][x] == X_N_E)
	{
		conf->state = HERO_LOSE;
		return ;
	}
	if (conf->map[y + 1][x] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.y++;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, x, conf->hero.y, DOWN);
}

void	move_hero_left(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y][x - 1] == ENEMY || conf->map[y][x - 1] == C_N_E
		|| conf->map[y][x - 1] == X_N_E)
	{
		conf->state = HERO_LOSE;
		return ;
	}
	if (conf->map[y][x - 1] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.x--;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, conf->hero.x, y, LEFT);
}

void	move_hero_right(void *param)
{
	t_config	*conf;
	const int	x = ((t_config *)param)->hero.x;
	const int	y = ((t_config *)param)->hero.y;

	conf = (t_config *)param;
	if (conf->map[y][x + 1] == ENEMY || conf->map[y][x + 1] == C_N_E
		|| conf->map[y][x + 1] == X_N_E)
	{
		conf->state = HERO_LOSE;
		return ;
	}
	if (conf->map[y][x + 1] != WALL)
	{
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		conf->hero.x++;
		conf->num_moves++;
		render_num_moves(conf, 10, 10);
	}
	update_status(conf, conf->hero.x, y, RIGHT);
}

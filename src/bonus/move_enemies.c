/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:41:49 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 17:59:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	update_enemy(t_config *conf, int x, int y, int direction)
{
	char	tile;

	tile = conf->map[y][x];
	render_tile(conf, x, y, get_bg_tile(conf, tile));
	if (tile == COIN || tile == C_N_E)
	{
		conf->map[y][x] = C_N_E;
		render_tile(conf, x, y, get_fg_tile(conf, COIN));
	}
	else if (tile == EXIT || tile == X_N_E)
		conf->map[y][x] = X_N_E;
	else
		conf->map[y][x] = ENEMY;
	if (direction == UP)
		render_tile(conf, x, y, &(conf->enemy_frms.up));
	else if (direction == DOWN)
		render_tile(conf, x, y, &(conf->enemy_frms.down));
	else if (direction == LEFT)
		render_tile(conf, x, y, &(conf->enemy_frms.left));
	else if (direction == RIGHT)
		render_tile(conf, x, y, &(conf->enemy_frms.right));
	mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->scr.img, 0, 0);
	if (conf->state == ENEMY_TURN)
		conf->state = HERO_TURN;
}

void	move_enemy_up(t_config *conf, t_enemy *enemy)
{
	const int	x = enemy->sprite.x;
	const int	y = enemy->sprite.y;

	if (x == conf->hero.x && y - 1 == conf->hero.y)
		conf->state = HERO_LOSE;
	else if (conf->map[y - 1][x] != WALL)
	{
		if (conf->map[y][x] == C_N_E)
			conf->map[y][x] = COIN;
		else if (conf->map[y][x] == X_N_E)
			conf->map[y][x] = EXIT;
		else
			conf->map[y][x] = EMPTY;
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		render_tile(conf, x, y, get_fg_tile(conf, conf->map[y][x]));
		enemy->sprite.y--;
	}
	update_enemy(conf, x, enemy->sprite.y, UP);
}

void	move_enemy_down(t_config *conf, t_enemy *enemy)
{
	const int	x = enemy->sprite.x;
	const int	y = enemy->sprite.y;

	if (x == conf->hero.x && y + 1 == conf->hero.y)
		conf->state = HERO_LOSE;
	else if (conf->map[y + 1][x] != WALL)
	{
		if (conf->map[y][x] == C_N_E)
			conf->map[y][x] = COIN;
		else if (conf->map[y][x] == X_N_E)
			conf->map[y][x] = EXIT;
		else
			conf->map[y][x] = EMPTY;
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		render_tile(conf, x, y, get_fg_tile(conf, conf->map[y][x]));
		enemy->sprite.y++;
	}
	update_enemy(conf, x, enemy->sprite.y, DOWN);
}

void	move_enemy_left(t_config *conf, t_enemy *enemy)
{
	const int	x = enemy->sprite.x;
	const int	y = enemy->sprite.y;

	if (x - 1 == conf->hero.x && y == conf->hero.y)
		conf->state = HERO_LOSE;
	else if (conf->map[y][x - 1] != WALL)
	{
		if (conf->map[y][x] == C_N_E)
			conf->map[y][x] = COIN;
		else if (conf->map[y][x] == X_N_E)
			conf->map[y][x] = EXIT;
		else if (conf->map[y][x] == ENEMY)
			conf->map[y][x] = EMPTY;
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		render_tile(conf, x, y, get_fg_tile(conf, conf->map[y][x]));
		enemy->sprite.x--;
	}
	update_enemy(conf, enemy->sprite.x, y, LEFT);
}

void	move_enemy_right(t_config *conf, t_enemy *enemy)
{
	const int	x = enemy->sprite.x;
	const int	y = enemy->sprite.y;

	if (x + 1 == conf->hero.x && y == conf->hero.y)
		conf->state = HERO_LOSE;
	else if (conf->map[y][x + 1] != WALL)
	{
		if (conf->map[y][x] == C_N_E)
			conf->map[y][x] = COIN;
		else if (conf->map[y][x] == X_N_E)
			conf->map[y][x] = EXIT;
		else
			conf->map[y][x] = EMPTY;
		render_tile(conf, x, y, get_bg_tile(conf, conf->map[y][x]));
		render_tile(conf, x, y, get_fg_tile(conf, conf->map[y][x]));
		enemy->sprite.x++;
	}
	update_enemy(conf, enemy->sprite.x, y, RIGHT);
}

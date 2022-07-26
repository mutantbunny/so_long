/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:08 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 15:58:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

void	initialize_start(t_config *conf, int x, int y)
{
	conf->hero.x = x;
	conf->hero.y = y;
	conf->map[y][x] = EMPTY;
}

void	initialize_tiles(t_config *conf)
{
	int		x;
	int		y;
	char	ch;

	y = 0;
	while (y < conf->map_height)
	{
		x = 0;
		while (x < conf->map_width)
		{
			ch = conf->map[y][x];
			if (ch == COIN)
				conf->num_coins++;
			else if (ch == START)
				initialize_start(conf, x, y);
			else if (ch == ENEMY)
				initialize_enemy(conf, x, y);
			render_tile(conf, x, y, get_bg_tile(conf, ch));
			render_tile(conf, x, y, get_fg_tile(conf, ch));
			x++;
		}
		y++;
	}
}

int	check_window_size(void *mlx, int win_width, int win_height)
{
	int	scr_width;
	int	scr_height;

	mlx_get_screen_size(mlx, &scr_width, &scr_height);
	if (win_width > scr_width || win_height > scr_height)
		return (ERR_SIZE);
	return (0);
}

void	initialize_conf(t_config *conf)
{
	conf->num_moves = 0;
	conf->num_coins = 0;
	conf->state = HERO_TURN;
	conf->map = NULL;
	conf->mlx = NULL;
	conf->mlx_win = NULL;
	conf->enemies = NULL;
	conf->scr.img = NULL;
	conf->coin.img = NULL;
	conf->empty.img = NULL;
	conf->exit.img = NULL;
	conf->wall.img = NULL;
	conf->hero_frms.up.img = NULL;
	conf->hero_frms.down.img = NULL;
	conf->hero_frms.left.img = NULL;
	conf->hero_frms.right.img = NULL;
	conf->enemy_frms.up.img = NULL;
	conf->enemy_frms.down.img = NULL;
	conf->enemy_frms.left.img = NULL;
	conf->enemy_frms.right.img = NULL;
	conf->moves_digits.img = NULL;
	conf->moves_text.img = NULL;
}

int	initialize_game(t_config *conf)
{
	int		h_px;
	int		w_px;

	conf->mlx = mlx_init();
	if (!conf->mlx)
		return (ERR_MLX);
	if (load_tiles(conf))
		return (ERR_TILE);
	conf->tile_size = conf->empty.height;
	h_px = conf->map_height * conf->tile_size;
	w_px = conf->map_width * conf->tile_size;
	if (check_window_size(conf->mlx, w_px, h_px))
		return (ERR_SIZE);
	conf->scr.img = mlx_new_image(conf->mlx, w_px, h_px);
	conf->mlx_win = mlx_new_window(conf->mlx, w_px, h_px, "So Long");
	if (!conf->scr.img || !conf->mlx_win)
		return (ERR_WIN);
	conf->scr.addr = mlx_get_data_addr(conf->scr.img,
			&(conf->scr.bpp), &(conf->scr.l_len), &(conf->scr.endian));
	initialize_tiles(conf);
	srand((unsigned int)((unsigned long)conf->scr.addr & 0xFFFFFFFFUL));
	return (0);
}

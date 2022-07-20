/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:08 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/19 23:17:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	load_hero_tiles(t_config *conf)
{
	conf->hero.up.img = mlx_xpm_file_to_image(conf->mlx, HERO_U_XPM,
			&(conf->hero.up.width), &(conf->hero.up.height));
	conf->hero.up.addr = mlx_get_data_addr(conf->hero.up.img,
			&(conf->hero.up.bpp), &(conf->hero.up.l_len),
			&(conf->hero.up.endian));
	conf->hero.down.img = mlx_xpm_file_to_image(conf->mlx, HERO_D_XPM,
			&(conf->hero.down.width), &(conf->hero.down.height));
	conf->hero.down.addr = mlx_get_data_addr(conf->hero.down.img,
			&(conf->hero.down.bpp), &(conf->hero.down.l_len),
			&(conf->hero.down.endian));
	conf->hero.left.img = mlx_xpm_file_to_image(conf->mlx, HERO_L_XPM,
			&(conf->hero.left.width), &(conf->hero.left.height));
	conf->hero.left.addr = mlx_get_data_addr(conf->hero.left.img,
			&(conf->hero.left.bpp), &(conf->hero.left.l_len),
			&(conf->hero.left.endian));
	conf->hero.right.img = mlx_xpm_file_to_image(conf->mlx, HERO_R_XPM,
			&(conf->hero.right.width), &(conf->hero.right.height));
	conf->hero.right.addr = mlx_get_data_addr(conf->hero.right.img,
			&(conf->hero.right.bpp), &(conf->hero.right.l_len),
			&(conf->hero.right.endian));
	if (!conf->hero.up.img || !conf->hero.down.img
		|| !conf->hero.left.img || !conf->hero.right.img)
		return (1);
	return (0);
}

int	load_tiles(t_config *conf)
{
	conf->coin.img = mlx_xpm_file_to_image(conf->mlx, COIN_XPM,
			&(conf->coin.width), &(conf->coin.height));
	conf->coin.addr = mlx_get_data_addr(conf->coin.img, &(conf->coin.bpp),
			&(conf->coin.l_len), &(conf->coin.endian));
	conf->empty.img = mlx_xpm_file_to_image(conf->mlx, EMPTY_XPM,
			&(conf->empty.width), &(conf->empty.height));
	conf->empty.addr = mlx_get_data_addr(conf->empty.img, &(conf->empty.bpp),
			&(conf->empty.l_len), &(conf->empty.endian));
	conf->exit.img = mlx_xpm_file_to_image(conf->mlx, EXIT_XPM,
			&(conf->exit.width), &(conf->exit.height));
	conf->exit.addr = mlx_get_data_addr(conf->exit.img, &(conf->exit.bpp),
			&(conf->exit.l_len), &(conf->exit.endian));
	conf->wall.img = mlx_xpm_file_to_image(conf->mlx, WALL_XPM,
			&(conf->wall.width), &(conf->wall.height));
	conf->wall.addr = mlx_get_data_addr(conf->wall.img, &(conf->wall.bpp),
			&(conf->wall.l_len), &(conf->wall.endian));
	if (!conf->coin.img || !conf->empty.img || !conf->exit.img
		|| !conf->wall.img || load_hero_tiles(conf))
		return (1);
	return (0);
}

t_image	*get_tile(t_config *conf, char ch)
{
	if (ch == WALL)
		return (&(conf->wall));
	if (ch == EMPTY)
		return (&(conf->empty));
	if (ch == COIN)
		return (&(conf->coin));
	if (ch == START)
		return (&(conf->hero.right));
	if (ch == EXIT)
		return (&(conf->exit));
	return (NULL);
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
			{
				conf->hero.x = x;
				conf->hero.y = y;
				conf->map[y][x] = EMPTY;
			}
			render_tile(conf, x, y, get_tile(conf, ch));
			x++;
		}
		y++;
	}
}

int	initialize_game(t_config *conf)
{
	int		h_px;
	int		w_px;

	conf->num_moves = 0;
	conf->num_coins = 0;
	conf->tile_size = conf->empty.height;
	h_px = conf->map_height * conf->tile_size;
	w_px = conf->map_width * conf->tile_size;
	conf->mlx_win = mlx_new_window(conf->mlx, w_px, h_px, "So Long");
	if (h_px > MAX_HEIGHT || w_px > MAX_WIDTH)
		return (1);
	conf->scr.img = mlx_new_image(conf->mlx, w_px, h_px);
	conf->scr.addr = mlx_get_data_addr(conf->scr.img,
			&(conf->scr.bpp), &(conf->scr.l_len), &(conf->scr.endian));
	initialize_tiles(conf);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:03:25 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 14:55:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	load_enemy_tiles(t_config *conf)
{
	conf->enemy_frms.up.img = mlx_xpm_file_to_image(conf->mlx, ENEMY_U_XPM,
			&(conf->enemy_frms.up.width), &(conf->enemy_frms.up.height));
	conf->enemy_frms.down.img = mlx_xpm_file_to_image(conf->mlx, ENEMY_D_XPM,
			&(conf->enemy_frms.down.width), &(conf->enemy_frms.down.height));
	conf->enemy_frms.left.img = mlx_xpm_file_to_image(conf->mlx, ENEMY_L_XPM,
			&(conf->enemy_frms.left.width), &(conf->enemy_frms.left.height));
	conf->enemy_frms.right.img = mlx_xpm_file_to_image(conf->mlx, ENEMY_R_XPM,
			&(conf->enemy_frms.right.width), &(conf->enemy_frms.right.height));
	if (!conf->enemy_frms.up.img || !conf->enemy_frms.down.img
		|| !conf->enemy_frms.left.img || !conf->enemy_frms.right.img)
		return (ERR_TILE);
	conf->enemy_frms.up.addr = mlx_get_data_addr(conf->enemy_frms.up.img,
			&(conf->enemy_frms.up.bpp), &(conf->enemy_frms.up.l_len),
			&(conf->enemy_frms.up.endian));
	conf->enemy_frms.down.addr = mlx_get_data_addr(conf->enemy_frms.down.img,
			&(conf->enemy_frms.down.bpp), &(conf->enemy_frms.down.l_len),
			&(conf->enemy_frms.down.endian));
	conf->enemy_frms.left.addr = mlx_get_data_addr(conf->enemy_frms.left.img,
			&(conf->enemy_frms.left.bpp), &(conf->enemy_frms.left.l_len),
			&(conf->enemy_frms.left.endian));
	conf->enemy_frms.right.addr = mlx_get_data_addr(conf->enemy_frms.right.img,
			&(conf->enemy_frms.right.bpp), &(conf->enemy_frms.right.l_len),
			&(conf->enemy_frms.right.endian));
	return (0);
}

int	load_hero_tiles(t_config *conf)
{
	conf->hero_frms.up.img = mlx_xpm_file_to_image(conf->mlx, HERO_U_XPM,
			&(conf->hero_frms.up.width), &(conf->hero_frms.up.height));
	conf->hero_frms.down.img = mlx_xpm_file_to_image(conf->mlx, HERO_D_XPM,
			&(conf->hero_frms.down.width), &(conf->hero_frms.down.height));
	conf->hero_frms.left.img = mlx_xpm_file_to_image(conf->mlx, HERO_L_XPM,
			&(conf->hero_frms.left.width), &(conf->hero_frms.left.height));
	conf->hero_frms.right.img = mlx_xpm_file_to_image(conf->mlx, HERO_R_XPM,
			&(conf->hero_frms.right.width), &(conf->hero_frms.right.height));
	if (!conf->hero_frms.up.img || !conf->hero_frms.down.img
		|| !conf->hero_frms.left.img || !conf->hero_frms.right.img)
		return (ERR_TILE);
	conf->hero_frms.up.addr = mlx_get_data_addr(conf->hero_frms.up.img,
			&(conf->hero_frms.up.bpp), &(conf->hero_frms.up.l_len),
			&(conf->hero_frms.up.endian));
	conf->hero_frms.down.addr = mlx_get_data_addr(conf->hero_frms.down.img,
			&(conf->hero_frms.down.bpp), &(conf->hero_frms.down.l_len),
			&(conf->hero_frms.down.endian));
	conf->hero_frms.left.addr = mlx_get_data_addr(conf->hero_frms.left.img,
			&(conf->hero_frms.left.bpp), &(conf->hero_frms.left.l_len),
			&(conf->hero_frms.left.endian));
	conf->hero_frms.right.addr = mlx_get_data_addr(conf->hero_frms.right.img,
			&(conf->hero_frms.right.bpp), &(conf->hero_frms.right.l_len),
			&(conf->hero_frms.right.endian));
	conf->hero.frames = &(conf->hero_frms);
	return (0);
}

int	load_tiles(t_config *conf)
{
	conf->coin.img = mlx_xpm_file_to_image(conf->mlx, COIN_XPM,
			&(conf->coin.width), &(conf->coin.height));
	conf->empty.img = mlx_xpm_file_to_image(conf->mlx, EMPTY_XPM,
			&(conf->empty.width), &(conf->empty.height));
	conf->exit.img = mlx_xpm_file_to_image(conf->mlx, EXIT_XPM,
			&(conf->exit.width), &(conf->exit.height));
	conf->wall.img = mlx_xpm_file_to_image(conf->mlx, WALL_XPM,
			&(conf->wall.width), &(conf->wall.height));
	if (load_hero_tiles(conf) || load_text_tiles(conf)
		|| load_enemy_tiles(conf) || !conf->coin.img
		|| !conf->empty.img || !conf->exit.img || !conf->wall.img)
		return (ERR_TILE);
	conf->coin.addr = mlx_get_data_addr(conf->coin.img, &(conf->coin.bpp),
			&(conf->coin.l_len), &(conf->coin.endian));
	conf->empty.addr = mlx_get_data_addr(conf->empty.img, &(conf->empty.bpp),
			&(conf->empty.l_len), &(conf->empty.endian));
	conf->exit.addr = mlx_get_data_addr(conf->exit.img, &(conf->exit.bpp),
			&(conf->exit.l_len), &(conf->exit.endian));
	conf->wall.addr = mlx_get_data_addr(conf->wall.img, &(conf->wall.bpp),
			&(conf->wall.l_len), &(conf->wall.endian));
	return (0);
}

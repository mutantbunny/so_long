/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:08 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/22 05:24:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	load_tiles(t_config	*conf, char *wall, char *empty, char *exit)
{
	conf->tiles.wall.img = mlx_xpm_file_to_image(conf->mlx, wall,
			&(conf->tiles.wall.width), &(conf->tiles.wall.height));
	conf->tiles.wall.addr = mlx_get_data_addr(conf->tiles.wall.img,
			&(conf->tiles.wall.bpp), &(conf->tiles.wall.l_len),
			&(conf->tiles.wall.endian));
	conf->tiles.empty.img = mlx_xpm_file_to_image(conf->mlx, empty,
			&(conf->tiles.empty.width), &(conf->tiles.empty.height));
	conf->tiles.empty.addr = mlx_get_data_addr(conf->tiles.empty.img,
			&(conf->tiles.empty.bpp), &(conf->tiles.empty.l_len),
			&(conf->tiles.empty.endian));
	conf->tiles.exit.img = mlx_xpm_file_to_image(conf->mlx, exit,
			&(conf->tiles.exit.width), &(conf->tiles.exit.height));
	conf->tiles.exit.addr = mlx_get_data_addr(conf->tiles.exit.img,
			&(conf->tiles.exit.bpp), &(conf->tiles.exit.l_len),
			&(conf->tiles.exit.endian));
}

int	build_initial_screen(t_config *conf)
{
	int	h_px;
	int	w_px;
	int	x;
	int	y;
	int	sprite_size;

	sprite_size = conf->tiles.empty.height;
	h_px = conf->map_height * sprite_size;
	w_px = conf->map_width * sprite_size;
	if (h_px > WINDOW_HEIGHT || w_px > WINDOW_WIDTH)
		return (1);
	conf->scr_img.img = mlx_new_image(conf->mlx, w_px, h_px);
	y = 0;
	while (conf->map[y] != NULL)
	{
		x = 0;
		while (conf->map[x][y] != '\0')
		{
		}
	}
	return (0);
}

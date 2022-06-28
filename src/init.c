/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:08 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/22 21:53:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	load_tiles(t_config	*conf, char *wall, char *empty, char *exit)
{
	conf->wall.img = mlx_xpm_file_to_image(conf->mlx, wall,
			&(conf->wall.width), &(conf->wall.height));
	conf->wall.addr = mlx_get_data_addr(conf->wall.img, &(conf->wall.bpp),
			&(conf->wall.l_len), &(conf->wall.endian));
	conf->empty.img = mlx_xpm_file_to_image(conf->mlx, empty,
			&(conf->empty.width), &(conf->empty.height));
	conf->empty.addr = mlx_get_data_addr(conf->empty.img, &(conf->empty.bpp),
			&(conf->empty.l_len), &(conf->empty.endian));
	conf->exit.img = mlx_xpm_file_to_image(conf->mlx, exit,
			&(conf->exit.width), &(conf->exit.height));
	conf->exit.addr = mlx_get_data_addr(conf->exit.img, &(conf->exit.bpp),
			&(conf->exit.l_len), &(conf->exit.endian));
}

int	initialize_screen(t_config *conf)
{
	int	h_px;
	int	w_px;
	int	x;
	int	y;

	conf->sprite_size = conf->empty.height;
	h_px = conf->map_height * conf->sprite_size;
	w_px = conf->map_width * conf->sprite_size;
	if (h_px > MAX_HEIGHT || w_px > MAX_WIDTH)
		return (1);
	conf->scr_buf.img = mlx_new_image(conf->mlx, w_px, h_px);
	y = 0;
	while (conf->map[y] != NULL)
	{
		x = 0;
		while (conf->map[x][y] != '\0')
			render_tile(conf, x, y);
	}
	return (0);
}

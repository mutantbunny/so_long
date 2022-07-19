/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/19 02:27:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_tile(t_config *conf, int scr_x, int scr_y, t_image *tile)
{
	int		x;
	int		y;
	char	*start;
	int		bpp;

	y = 0;
	bpp = conf->scr.bpp / 8;
	start = conf->scr.addr + scr_y * conf->tile_size * conf->scr.l_len
		+ scr_x * conf->tile_size * bpp;

	while (y < conf->tile_size)
	{
		x = 0;
		while (x < conf->tile_size)
		{
			*(unsigned int *)(start + x * bpp)
				= *(unsigned int *)(tile->addr + y * tile->l_len + x * bpp);
			x++;
		}
		start += (conf->scr.l_len);
		y++;
	}
}

void	draw_hero_up(t_config *conf, int x, int y)
{
	render_tile(conf, x, y, &(conf->hero.up));
}

void	draw_hero_down(t_config *conf, int x, int y)
{
	render_tile(conf, x, y, &(conf->hero.down));
}

void	draw_hero_left(t_config *conf, int x, int y)
{
	render_tile(conf, x, y, &(conf->hero.left));
}

void	draw_hero_right(t_config *conf, int x, int y)
{
	render_tile(conf, x, y, &(conf->hero.right));
}

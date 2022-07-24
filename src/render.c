/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 02:30:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	render_tile(t_config *conf, int scr_x, int scr_y, t_image *tile)
{
	int				x;
	int				y;
	char			*start;
	const int		bpp = conf->scr.bpp / 8;
	unsigned int	pixel;

	if (!tile)
		return ;
	y = 0;
	start = conf->scr.addr + scr_y * conf->tile_size * conf->scr.l_len
		+ scr_x * conf->tile_size * bpp;
	while (y < conf->tile_size)
	{
		x = 0;
		while (x < conf->tile_size)
		{
			pixel = *(unsigned int *)(tile->addr + y * tile->l_len + x * bpp);
			if (!(pixel & 0xFF000000))
				*(unsigned int *)(start + x * bpp) = pixel;
			x++;
		}
		start += (conf->scr.l_len);
		y++;
	}
}

t_image	*get_bg_tile(t_config *conf, char ch)
{
	if (ch == WALL)
		return (&(conf->wall));
	if (ch == EMPTY || ch == COIN || ch == START)
		return (&(conf->empty));
	if (ch == EXIT)
		return (&(conf->exit));
	return (NULL);
}

t_image	*get_fg_tile(t_config *conf, char ch)
{
	if (ch == COIN)
		return (&(conf->coin));
	if (ch == START)
		return (&(conf->hero.right));
	return (NULL);
}

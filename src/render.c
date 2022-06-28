/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/23 03:04:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	copy_image(t_image *dest, t_image *src, int x, int y)
{
	return (1);
}

int	merge_images(t_config *conf, t_sprite *fgnd, int x, int y)
{
	return (1);
}

int	render_tile(t_config *conf, int x, int y)
{
	const char	tile_type = conf->map[y][x];

	if (tile_type == EMPTY)
		return (copy_image(&(conf->scr_buf), &(conf->empty), x, y));
	if (tile_type == WALL)
		return (copy_image(&(conf->scr_buf), &(conf->wall), x, y));
	if (tile_type == COIN)
		return (merge_images(conf, &(conf->coin), x, y));
	if (tile_type == START)
		return (merge_images(conf, &(conf->hero), x, y));
	if (tile_type == EXIT)
		return (copy_image(&(conf->scr_buf), &(conf->exit), x, y));
	return (1);
}

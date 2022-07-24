/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 02:29:19 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 04:32:54 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	load_text_tiles(t_config *conf)
{
	conf->moves_text.img = NULL;
	conf->moves_digits.img = NULL;
	conf->moves_text.img = mlx_xpm_file_to_image(conf->mlx, TEXT_XPM,
			&(conf->moves_text.width), &(conf->moves_text.height));
	conf->moves_digits.img = mlx_xpm_file_to_image(conf->mlx, DIGITS_XPM,
			&(conf->moves_digits.width), &(conf->moves_digits.height));
	if (!conf->moves_text.img || !conf->moves_digits.img)
		return (ERR_TILE);
	conf->moves_text.addr = mlx_get_data_addr(conf->moves_text.img,
			&(conf->moves_text.bpp), &(conf->moves_text.l_len),
			&(conf->moves_text.endian));
	conf->moves_digits.addr = mlx_get_data_addr(conf->moves_digits.img,
			&(conf->moves_digits.bpp), &(conf->moves_digits.l_len),
			&(conf->moves_digits.endian));
	return (0);
}

void	render_digit(t_config *conf, int x_offset, int y_offset, int digit)
{
	int				x;
	int				y;
	char			*start;
	const int		bpp = conf->scr.bpp / 8;
	unsigned int	pixel;

	y = 0;
	start = conf->scr.addr + y_offset * conf->scr.l_len + x_offset * bpp;
	while (y < conf->moves_digits.width)
	{
		x = 0;
		while (x < conf->moves_digits.width)
		{
			pixel = *(unsigned int *)(conf->moves_digits.addr
					+ (conf->moves_digits.width * digit + y)
					* conf->moves_digits.l_len + x * bpp);
			if (!(pixel & 0xFF000000))
				*(unsigned int *)(start + x * bpp) = pixel;
			x++;
		}
		start += (conf->scr.l_len);
		y++;
	}
}

void	render_moves_digits(t_config *conf, int x, int y, unsigned int nbr)
{
	int		pos;
	int		x_offset;

	pos = 4;
	if (nbr == 0)
	{
		x_offset = (conf->moves_digits.width + 2) * pos;
		render_digit(conf, x + x_offset, y, 0);
	}
	else
	{
		if (nbr > 9999)
			nbr = 9999;
		while (nbr != 0)
		{
			x_offset = (conf->moves_digits.width + 2) * pos--;
			render_digit(conf, x + x_offset, y, nbr % 10);
			nbr /= 10;
		}
	}
}

void	render_moves_text(t_config *conf, int x_offset, int y_offset)
{
	int				x;
	int				y;
	char			*start;
	const int		bpp = conf->scr.bpp / 8;
	unsigned int	pixel;

	y = 0;
	start = conf->scr.addr + y_offset * conf->scr.l_len
		+ x_offset * bpp;
	while (y < conf->moves_text.height)
	{
		x = 0;
		while (x < conf->moves_text.width)
		{
			pixel = *(unsigned int *)(conf->moves_text.addr
					+ y * conf->moves_text.l_len + x * bpp);
			if (!(pixel & 0xFF000000))
				*(unsigned int *)(start + x * bpp) = pixel;
			x++;
		}
		start += (conf->scr.l_len);
		y++;
	}
}

void	render_num_moves(t_config *conf, int x, int y)
{
	render_tile(conf, 0, 0, &(conf->wall));
	render_tile(conf, 1, 0, &(conf->wall));
	render_tile(conf, 2, 0, &(conf->wall));
	render_moves_text(conf, x, y);
	render_moves_digits(conf, x + conf->moves_text.width, y,
		(unsigned int)conf->num_moves);
}

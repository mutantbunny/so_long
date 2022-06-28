/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/22 21:43:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	exit_program(void *param)
{
	const t_config	*conf = (t_config *)param;

	mlx_destroy_image(conf->mlx, conf->scr_buf.img);
	mlx_destroy_window(conf->mlx, conf->mlx_win);
	exit(0);
}

int	main(void)
{
	t_config	conf;

	conf.mlx = mlx_init();
	conf.mlx_win = mlx_new_window(conf.mlx, 1920, 1080, "Hello world!");
	load_tiles(&conf, "wall.xpm", "empty.xpm", "exit.xpm");
	conf.scr_buf.img = mlx_new_image(conf.mlx, 1920, 1080);
	conf.scr_buf.addr = mlx_get_data_addr(conf.scr_buf.img, &conf.scr_buf.bpp,
			&conf.scr_buf.l_len, &conf.scr_buf.endian);
	mlx_put_image_to_window(conf.mlx, conf.mlx_win, conf.scr_buf.img, 0, 0);
	mlx_key_hook(conf.mlx_win, key_hook, &conf);
	mlx_loop(conf.mlx);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/22 05:31:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	exit_program(void *param)
{
	const t_config	*conf = (t_config *)param;

	mlx_destroy_image(conf->mlx, conf->scr_img.img);
	mlx_destroy_window(conf->mlx, conf->mlx_win);
	exit(0);
}

int	main(void)
{
	t_config	conf;

	conf.mlx = mlx_init();
	conf.mlx_win = mlx_new_window(conf.mlx, 1920, 1080, "Hello world!");
	load_tiles(&conf, "wall.xpm", "empty.xpm", "exit.xpm");
	conf.scr_img.img = mlx_new_image(conf.mlx, 1920, 1080);
	conf.scr_img.addr = mlx_get_data_addr(conf.scr_img.img, &conf.scr_img.bpp,
			&conf.scr_img.l_len, &conf.scr_img.endian);
	mlx_put_image_to_window(conf.mlx, conf.mlx_win, conf.scr_img.img, 0, 0);
	mlx_key_hook(conf.mlx_win, key_hook, &conf);
	mlx_loop(conf.mlx);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/19 23:18:32 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	exit_program(void *param)
{
	const t_config	*conf = (t_config *)param;

	mlx_destroy_image(conf->mlx, conf->scr.img);
	mlx_destroy_image(conf->mlx, conf->coin.img);
	mlx_destroy_image(conf->mlx, conf->empty.img);
	mlx_destroy_image(conf->mlx, conf->exit.img);
	mlx_destroy_image(conf->mlx, conf->wall.img);
	mlx_destroy_image(conf->mlx, conf->hero.up.img);
	mlx_destroy_image(conf->mlx, conf->hero.down.img);
	mlx_destroy_image(conf->mlx, conf->hero.left.img);
	mlx_destroy_image(conf->mlx, conf->hero.right.img);
	mlx_destroy_window(conf->mlx, conf->mlx_win);
	free(conf->map);
	exit(0);
}

void	add_hooks(t_config *conf)
{
	mlx_key_hook(conf->mlx_win, key_hook, conf);
	mlx_loop_hook(conf->mlx, loop_hook, conf);
	mlx_hook(conf->mlx_win, BTN_X, NO_EVENT, exit_program, conf);
}

int	main(int argc, char *argv[])
{
	t_config	conf;
	int			err;

	if (argc != 2)
	{
		ft_printf("Usage: %s map_name.ber\n", argv[0]);
		return (1);
	}
	conf.mlx = mlx_init();
	err = load_map(&conf, argv[1]);
	if (err)
		return (err);
	err = load_tiles(&conf);
	if (err)
		return (err);
	err = initialize_game(&conf);
	if (err)
		return (err);
	add_hooks(&conf);
	mlx_loop(conf.mlx);
}

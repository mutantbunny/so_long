/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:46 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/24 04:22:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	destroy_images(t_config *conf)
{
	if (conf->scr.img)
		mlx_destroy_image(conf->mlx, conf->scr.img);
	if (conf->coin.img)
		mlx_destroy_image(conf->mlx, conf->coin.img);
	if (conf->empty.img)
		mlx_destroy_image(conf->mlx, conf->empty.img);
	if (conf->exit.img)
		mlx_destroy_image(conf->mlx, conf->exit.img);
	if (conf->wall.img)
		mlx_destroy_image(conf->mlx, conf->wall.img);
	if (conf->hero.up.img)
		mlx_destroy_image(conf->mlx, conf->hero.up.img);
	if (conf->hero.down.img)
		mlx_destroy_image(conf->mlx, conf->hero.down.img);
	if (conf->hero.left.img)
		mlx_destroy_image(conf->mlx, conf->hero.left.img);
	if (conf->hero.right.img)
		mlx_destroy_image(conf->mlx, conf->hero.right.img);
}

void	cleanup(t_config *conf)
{
	char	**temp;

	if (conf->mlx)
	{
		destroy_images(conf);
		if (conf->mlx_win)
			mlx_destroy_window(conf->mlx, conf->mlx_win);
		mlx_destroy_display(conf->mlx);
		free(conf->mlx);
	}
	temp = conf->map;
	if (temp)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(conf->map);
	}
}

int	exit_program(void *param)
{
	cleanup((t_config *)param);
	exit(0);
}

void	exit_with_error(t_config *conf, int code)
{
	const char	*errors[] = {
		"Unknown error", "Invalid character in map",
		"Invalid map shape", "Invalid map filename extension",
		"Could not open map file", "Could not load tiles",
		"Map must contain at least 1 exit, 1 starting point and 1 collectible",
		"Map must be surrounded by walls", "Could not initialize game window",
		"Map is valid, but it is too big to show on this screen",
		"Could not initialize MiniLibX"
	};

	if (code > ERR_MLX)
		code = 0;
	cleanup(conf);
	ft_printf("Error\n%s.\n", errors[code]);
	exit(code);
}

int	main(int argc, char *argv[])
{
	t_config	conf;
	int			err;

	conf.mlx = NULL;
	conf.map = NULL;
	if (argc != 2)
	{
		ft_printf("Error\nInvalid arguments. Usage: %s map.ber\n", argv[0]);
		return (1);
	}
	err = load_map(&conf, argv[1]);
	if (err)
		exit_with_error(&conf, err);
	err = initialize_game(&conf);
	if (err)
		exit_with_error(&conf, err);
	add_hooks(&conf);
	mlx_loop(conf.mlx);
}

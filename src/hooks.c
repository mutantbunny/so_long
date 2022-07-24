/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:39 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/21 01:58:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_hook(int keycode, void *param)
{
	if (keycode == XK_UP)
		move_up(param);
	else if (keycode == XK_DOWN)
		move_down(param);
	else if (keycode == XK_LEFT)
		move_left(param);
	else if (keycode == XK_RIGHT)
		move_right(param);
	else if (keycode == XK_ESCAPE)
		exit_program(param);
	return (keycode);
}

int	loop_hook(void *param)
{
	const t_config	*conf = (t_config *)param;

	mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->scr.img, 0, 0);
	return (0);
}

void	add_hooks(t_config *conf)
{
	mlx_key_hook(conf->mlx_win, key_hook, conf);
	mlx_loop_hook(conf->mlx, loop_hook, conf);
	mlx_hook(conf->mlx_win, BTN_X, NO_EVENT, exit_program, conf);
}

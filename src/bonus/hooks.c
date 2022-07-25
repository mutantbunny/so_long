/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:39 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 02:32:51 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	key_hook(int keycode, void *param)
{
	if (((t_config *)param)->state == HERO_TURN)
	{
		if (keycode == XK_UP)
			move_hero_up(param);
		else if (keycode == XK_DOWN)
			move_hero_down(param);
		else if (keycode == XK_LEFT)
			move_hero_left(param);
		else if (keycode == XK_RIGHT)
			move_hero_right(param);
	}
	if (keycode == XK_ESCAPE)
		exit_program(param);
	return (keycode);
}

int	loop_hook(void *param)
{
	const t_config		*conf = (t_config *)param;

	mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->scr.img, 0, 0);
	if (conf->state == HERO_LOSE)
	{
		ft_printf("A snake bit you! You lost!\n");
		exit_program(param);
	}
	if (conf->state == ENEMY_TURN)
		handle_enemies((t_config *)conf);
	return (0);
}

void	add_hooks(t_config *conf)
{
	mlx_key_hook(conf->mlx_win, key_hook, conf);
	mlx_loop_hook(conf->mlx, loop_hook, conf);
	mlx_hook(conf->mlx_win, BTN_X, NO_EVENT, exit_program, conf);
}

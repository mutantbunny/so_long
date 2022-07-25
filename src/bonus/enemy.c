/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:19:19 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 02:39:35 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long_bonus.h>

int	initialize_enemy(t_config *conf, int x, int y)
{
	t_enemy	*new_enemy;

	new_enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!new_enemy)
		return (ERR_ENEMY);
	new_enemy->sprite.frames = &(conf->enemy_frms);
	new_enemy->sprite.x = x;
	new_enemy->sprite.y = y;
	new_enemy->next = conf->enemies;
	conf->enemies = new_enemy;
	return (0);
}

void	destroy_enemies(t_config *conf)
{
	t_enemy	*cur;
	t_enemy	*temp;

	cur = conf->enemies;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
}

void	destroy_enemy_images(t_config *conf)
{
	if (conf->enemy_frms.up.img)
		mlx_destroy_image(conf->mlx, conf->enemy_frms.up.img);
	if (conf->enemy_frms.down.img)
		mlx_destroy_image(conf->mlx, conf->enemy_frms.down.img);
	if (conf->enemy_frms.left.img)
		mlx_destroy_image(conf->mlx, conf->enemy_frms.left.img);
	if (conf->enemy_frms.right.img)
		mlx_destroy_image(conf->mlx, conf->enemy_frms.right.img);
}

void	handle_enemies(t_config *conf)
{
	t_enemy			*enemy;
	unsigned int	direction;

	enemy = conf->enemies;
	while (enemy)
	{
		direction = rand() % 4;
		if (direction == UP)
			move_enemy_up(conf, enemy);
		else if (direction == DOWN)
			move_enemy_down(conf, enemy);
		else if (direction == LEFT)
			move_enemy_left(conf, enemy);
		else if (direction == RIGHT)
			move_enemy_right(conf, enemy);
		enemy = enemy->next;
	}
}

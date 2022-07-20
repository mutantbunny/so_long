/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:56 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/20 02:24:53 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <ft_printf.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define XK_LEFT 0xff51
# define XK_UP 0xff52
# define XK_RIGHT 0xff53
# define XK_DOWN 0xff54
# define XK_ESCAPE 0xff1b
# define BTN_X 17
# define NO_EVENT 0L

# define BUFFER_SIZE 255
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080

# define COIN 'C'
# define EMPTY '0'
# define EXIT 'E'
# define START 'P'
# define WALL '1'

# define COIN_XPM "/home/coelho/projects/so_long/asset/capy/carot.xpm"
# define EMPTY_XPM "/home/coelho/projects/so_long/asset/capy/grass.xpm"
# define EXIT_XPM "/home/coelho/projects/so_long/asset/capy/water.xpm"
# define WALL_XPM "/home/coelho/projects/so_long/asset/capy/trees.xpm"

# define HERO_U_XPM "/home/coelho/projects/so_long/asset/capy/capy_up.xpm"
# define HERO_D_XPM "/home/coelho/projects/so_long/asset/capy/capy_down.xpm"
# define HERO_L_XPM "/home/coelho/projects/so_long/asset/capy/capy_left.xpm"
# define HERO_R_XPM "/home/coelho/projects/so_long/asset/capy/capy_right.xpm"

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		l_len;
	int		endian;
}	t_image;

typedef struct s_sprite
{
	t_image	up;
	t_image	down;
	t_image	left;
	t_image	right;
	int		x;
	int		y;
}	t_sprite;

typedef struct s_config
{
	void		*mlx;
	void		*mlx_win;
	t_image		wall;
	t_image		empty;
	t_image		exit;
	t_image		coin;
	t_image		scr;
	t_sprite	hero;
	int			map_width;
	int			map_height;
	int			tile_size;
	int			num_coins;
	int			num_moves;
	char		**map;
}	t_config;

// hooks.c
void	add_hooks(t_config *conf);
int		key_hook(int keycode, void *param);
int		loop_hook(void *param);

// init.c
t_image	*get_tile(t_config *conf, char ch);
int		load_hero_tiles(t_config *conf);
int		load_tiles(t_config	*conf);
int		initialize_game(t_config *conf);
void	initialize_tiles(t_config *conf);

// map.c
char	*resize_buffer(char *buf, int cur_size, int increment);
char	**get_map_file_contents(int fd);
int		load_map(t_config *conf, char *map_file);

// movement.c
void	move_up(void *conf);
void	move_down(void *conf);
void	move_left(void *conf);
void	move_right(void *conf);
void	update_status(t_config *conf, int x, int y, char tile);

// render.c
void	render_tile(t_config *conf, int scr_x, int scr_y, t_image *tile);
void	draw_hero_up(t_config *conf, int x, int y);
void	draw_hero_down(t_config *conf, int x, int y);
void	draw_hero_left(t_config *conf, int x, int y);
void	draw_hero_right(t_config *conf, int x, int y);

// so_long.c
int		exit_program(void *param);

// validation.c
int		validate_tile(t_config *conf, int x, int y, int start_count);
int		validate_map(t_config *conf);
int		validate_shape(t_config *conf);
int		validate_tiles(t_config *conf);
int		validate_walls(t_config *conf);
#endif

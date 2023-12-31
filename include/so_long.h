/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:56 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/28 00:36:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

// X-related constants
# define XK_LEFT 0xff51
# define XK_UP 0xff52
# define XK_RIGHT 0xff53
# define XK_DOWN 0xff54
# define XK_LOWER_A 0x0061
# define XK_LOWER_S 0x0073
# define XK_LOWER_D 0x0064
# define XK_LOWER_W 0x0077
# define XK_UPPER_A 0x0041
# define XK_UPPER_S 0x0053
# define XK_UPPER_D 0x0044
# define XK_UPPER_W 0x0057
# define XK_ESCAPE 0xff1b
# define BTN_X 17
# define NO_EVENT 0L

// Map file read buffer
# define BUFFER_SIZE 255

// Valid map tile codes
# define COIN 'C'
# define EMPTY '0'
# define EXIT 'E'
# define START 'P'
# define WALL '1'

// Movement directions
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

// General XPM files
# define COIN_XPM "../asset/capy/carrot.xpm"
# define EMPTY_XPM "../asset/capy/grass.xpm"
# define EXIT_XPM "../asset/capy/water.xpm"
# define WALL_XPM "../asset/capy/trees.xpm"

// hero XPM files
# define HERO_U_XPM "../asset/capy/capy_up.xpm"
# define HERO_D_XPM "../asset/capy/capy_down.xpm"
# define HERO_L_XPM "../asset/capy/capy_left.xpm"
# define HERO_R_XPM "../asset/capy/capy_right.xpm"

//Error codes
# define ERR_CHAR 1
# define ERR_SHAPE 2
# define ERR_EXT 3
# define ERR_OPEN 4
# define ERR_TILE 5
# define ERR_NUM 6
# define ERR_WALL 7
# define ERR_WIN 8
# define ERR_SIZE 9
# define ERR_MLX 10

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
int		load_hero_tiles(t_config *conf);
int		load_tiles(t_config	*conf);
int		initialize_game(t_config *conf);
void	initialize_tiles(t_config *conf);

// map.c
char	*resize_buffer(char *buf, int cur_size, int increment);
char	**get_map_file_contents(int fd);
int		load_map(t_config *conf, char *map_file);

// movement.c
void	move_hero_up(void *conf);
void	move_hero_down(void *conf);
void	move_hero_left(void *conf);
void	move_hero_right(void *conf);
void	update_status(t_config *conf, int x, int y, int direction);

// render.c
t_image	*get_bg_tile(t_config *conf, char ch);
t_image	*get_fg_tile(t_config *conf, char ch);
void	render_tile(t_config *conf, int scr_x, int scr_y, t_image *tile);

// so_long.c
int		exit_program(void *param);

// validation.c
int		validate_tile(t_config *conf, int x, int y, int start_count);
int		validate_map(t_config *conf);
int		validate_shape(t_config *conf);
int		validate_tiles(t_config *conf);
int		validate_walls(t_config *conf);
#endif

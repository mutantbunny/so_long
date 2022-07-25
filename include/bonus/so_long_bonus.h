/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:09:56 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/25 02:50:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// X-related constants
# define XK_LEFT 0xff51
# define XK_UP 0xff52
# define XK_RIGHT 0xff53
# define XK_DOWN 0xff54
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
# define ENEMY 'N'
# define C_N_E 'D'
# define X_N_E 'X'

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
# define TEXT_XPM "../asset/capy/move_text.xpm"
# define DIGITS_XPM "../asset/capy/digits.xpm"

// Hero XPM files
# define HERO_U_XPM "../asset/capy/capy_up.xpm"
# define HERO_D_XPM "../asset/capy/capy_down.xpm"
# define HERO_L_XPM "../asset/capy/capy_left.xpm"
# define HERO_R_XPM "../asset/capy/capy_right.xpm"

// Enemy XPM files
# define ENEMY_U_XPM "../asset/capy/snake_up.xpm"
# define ENEMY_D_XPM "../asset/capy/snake_down.xpm"
# define ENEMY_L_XPM "../asset/capy/snake_left.xpm"
# define ENEMY_R_XPM "../asset/capy/snake_right.xpm"

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
# define ERR_ENEMY 11

// Game state
# define HERO_TURN 1
# define ENEMY_TURN 2
# define HERO_WIN 3
# define HERO_LOSE 4

typedef struct s_frame
{
	char			*frame;
	struct s_frame	*next;
}	t_frame;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		l_len;
	int		endian;
}	t_image;

typedef struct s_frames
{
	t_image	up;
	t_image	down;
	t_image	left;
	t_image	right;
}	t_frames;

typedef struct s_sprite
{
	t_frames	*frames;
	int			x;
	int			y;
}	t_sprite;

typedef struct s_enemy
{
	t_sprite		sprite;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_config
{
	void		*mlx;
	void		*mlx_win;
	t_image		wall;
	t_image		empty;
	t_image		exit;
	t_image		coin;
	t_image		scr;
	t_image		moves_text;
	t_image		moves_digits;
	t_frames	hero_frms;
	t_sprite	hero;
	t_frames	enemy_frms;
	t_enemy		*enemies;
	int			map_width;
	int			map_height;
	int			tile_size;
	int			num_coins;
	int			num_moves;
	int			state;
	char		**map;
}	t_config;

// enemy.c
void	destroy_enemies(t_config *conf);
void	destroy_enemy_images(t_config *conf);
int		initialize_enemy(t_config *conf, int x, int y);
void	handle_enemies(t_config *conf);

// hooks.c
void	add_hooks(t_config *conf);
int		key_hook(int keycode, void *param);
int		loop_hook(void *param);

// init.c
int		check_window_size(void *mlx, int win_width, int win_height);
void	initialize_conf(t_config *conf);
int		initialize_game(t_config *conf);
void	initialize_start(t_config *conf, int x, int y);
void	initialize_tiles(t_config *conf);

// load_tiles.c
int		load_enemy_tiles(t_config *conf);
int		load_hero_tiles(t_config *conf);
int		load_tiles(t_config	*conf);

// map.c
char	*resize_buffer(char *buf, int cur_size, int increment);
char	**get_map_file_contents(int fd);
int		load_map(t_config *conf, char *map_file);

// move_enemies.c
void	update_enemy(t_config *conf, int x, int y, int direction);
void	move_enemy_up(t_config *conf, t_enemy *enemy);
void	move_enemy_down(t_config *conf, t_enemy *enemy);
void	move_enemy_left(t_config *conf, t_enemy *enemy);
void	move_enemy_right(t_config *conf, t_enemy *enemy);

// move_hero.c
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
void	cleanup(t_config *conf);
void	destroy_images(t_config *conf);
int		exit_program(void *param);
void	exit_with_error(t_config *conf, int code);

// text.c
int		load_text_tiles(t_config *conf);
void	render_digit(t_config *conf, int x_offset, int y_offset, int digit);
void	render_moves_digits(t_config *conf, int x, int y, unsigned int nbr);
void	render_moves_text(t_config *conf, int x_offset, int y_offset);
void	render_num_moves(t_config *conf, int x, int y);

// validation.c
int		validate_tile(t_config *conf, int x, int y, int start_count);
int		validate_map(t_config *conf);
int		validate_shape(t_config *conf);
int		validate_tiles(t_config *conf);
int		validate_walls(t_config *conf);
#endif

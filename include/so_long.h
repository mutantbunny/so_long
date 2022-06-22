#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define XK_Escape 0xff1b
# define BUFFER_SIZE 255
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# define EMPTY '0'
# define WALL '1'
# define COIN 'C'
# define EXIT 'E'
# define START 'P'
// # define HOSTILE 'H'

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		l_len;
	int		endian;
}	t_image;

typedef struct	s_tiles
{
	t_image	wall;
	t_image	empty;
	t_image	exit;
}	t_tiles;

typedef struct	s_frames
{
	void	**imgs;
	char	**addrs;
	int		n_frames;
	int		bpp;
	int		width;
	int		height;
	int		l_len;
	int		endian;
}	t_frames;

typedef struct	s_sprite
{
	t_frames	frames;
	int			cur_frame;
	int			x;
	int			y;
}	t_sprite;

typedef struct	s_config
{
	void		*mlx;
	void		*mlx_win;
	t_sprite	character;
	t_tiles		tiles;
	t_image		scr_img;
	int			map_width;
	int			map_height;
	char		**map;
}	t_config;

// hooks.c
int		key_hook(int keycode,void *param);

// init.c
void	load_tiles(t_config	*conf, char *wall, char *empty, char *exit);
int		build_initial_screen(t_config *conf);

// map.c
char	*resize_buffer(char *buf, size_t cur_size, size_t increment);
char	**get_map_file_contents(int fd);
int		load_map(t_config *conf, char *map_file);

// movement.c

// render.c

// so_long.c
void exit_program(void *param);

// validation.c
int		is_invalid_tile(char tile);
int		validate_map(t_config *conf);
int		validate_shape(t_config *conf);
int		validate_tiles(t_config *conf);
int		validate_walls(t_config *conf);
#endif
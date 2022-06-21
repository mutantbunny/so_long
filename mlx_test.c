#include <mlx.h>
#include <stdlib.h>
# include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define XK_Escape 0xff1b
#define BUFFER_SIZE 255
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define EMPTY '0'
#define WALL '1'
#define COIN 'C'
#define EXIT 'E'
#define START 'P'
// #define HOSTILE 'H'

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line_length;
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
	int		num_frames;
	int		bpp;
	int		width;
	int		height;
	int		l_len;
	int		endian;
}	t_frames;

typedef  struct	s_sprite
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
	t_image		map_img;
	size_t		map_width;
	size_t		map_height;
	char		**map;

}	t_config;

int key_hook(int keycode,void *param)
{
	const t_config	*conf = (t_config *)param;

	if (keycode == XK_Escape)
	{
		mlx_destroy_image(conf->mlx, conf->map.img);
		mlx_destroy_window(conf->mlx, conf->mlx_win);
	}
	exit(0);
	return (keycode);
}

void	load_tiles(t_config	*conf, char *wall, char *empty, char *exit)
{
	conf->tiles.wall.img = mlx_xpm_file_to_image(conf->mlx, wall,
		&(conf->tiles.wall.width), &(conf->tiles.wall.height));
	conf->tiles.wall.addr = mlx_get_data_addr(conf->tiles.wall.img,
		&(conf->tiles.wall.bpp), &(conf->tiles.wall.l_len),
		&(conf->tiles.wall.endian));
	conf->tiles.empty.img = mlx_xpm_file_to_image(conf->mlx, empty,
		&(conf->tiles.empty.width), &(conf->tiles.empty.height));
	conf->tiles.empty.addr = mlx_get_data_addr(conf->tiles.empty.img,
		&(conf->tiles.empty.bpp), &(conf->tiles.empty.l_len),
		&(conf->tiles.empty.endian));
	conf->tiles.exit.img = mlx_xpm_file_to_image(conf->mlx, exit,
		&(conf->tiles.exit.width), &(conf->tiles.exit.height));
	conf->tiles.exit.addr = mlx_get_data_addr(conf->tiles.exit.img,
		&(conf->tiles.exit.bpp), &(conf->tiles.exit.l_len),
		&(conf->tiles.exit.endian));
}

char *resize_buffer(char *buf, size_t cur_size, size_t increment)
{
	char	*new_buf;
	int		index;

	new_buf = (char *)malloc(cur_size + increment);
	index = 0;
	while (index < cur_size)
	{
		new_buf[index] = buf[index];
		index++;
	}
	free(buf);
	return (new_buf);
}

char **get_map_file_content(int fd)
{
	ssize_t	num_read;
	int		start;
	int		cur_size;
	char	*buf;
	char	**split_buf;

	num_read = 1;
	start = 0;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	while (num_read)
	{
		if (buf == NULL)
			return (NULL);
		num_read = read(fd, *buf + start, BUFFER_SIZE);
		if (num_read < 0)
			return (NULL);
		(*buf)[num_read] = '\0';
		if (num_read == BUFFER_SIZE)
			*buf = resize_buffer(*buf, start + BUFFER_SIZE + 1, BUFFER_SIZE);
		start += num_read;
	}
	split_buf = ft_split(buf);
	free(buf);
	return (split_buf);
}

int validate_tile(char tile)
{
	return (map[y][x++] != EMPTY
		&& map[y][x++] != WALL
		&& map[y][x++] != COIN
		&& map[y][x++] != EXIT
		&& map[y][x++] != START)
}

int validate_map(char **map, int *width, int *height)
{
	int x;
	int y;

	if (map == NULL || *map == NULL)
		return (1);
	*width = 0;
	while ((*map)[*width] != '\0')
		*width++;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (!validate_map(map[y][x++]))
				return (1)
		}
		if (x != *width)
			return (1);
		y++;
	}
	*height = y;
	return (0);
}

int build_map_image(t_config *conf)
{
	int h_px;
	int	w_px;
	int x;
	int y;
	int	sprite_size;

	sprite_size = conf->tiles.empty.height;
	h_px = conf->map_height * sprite_size;
	w_px = conf->map_width * sprite_size;
	if (h_px > WINDOW_HEIGHT || w_px > WINDOW_WIDTH)
		return (1);
	conf->map_img = mlx_new_image(conf->mlx, w_px, h_px);
	y = 0;
	while (conf->map[y] != NULL)
	{
		x = 0;
		while (conf->map[x][y] != '\0')

	}
}

int	load_map(t_config *conf, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 3)
		return (1);
	conf->map = get_map_file_content(fd);
	if (!validate_map(conf->map, &(conf->width), &(conf->height)));
		return (1);
	close(fd);
	return (0);
}

int	main(void)
{
	t_config	conf;

	conf.mlx = mlx_init();
	conf.mlx_win = mlx_new_window(conf.mlx, 1920, 1080, "Hello world!");
	load_tiles(&conf, "wall.xpm", "empty.xpm", "exit.xpm");
	conf.map.img = mlx_new_image(conf.mlx, 1920, 1080);
	conf.map.addr = mlx_get_data_addr(conf.map.img, &conf.map.bpp, &conf.map.line_length, &conf.map.endian);
	mlx_put_image_to_window(conf.mlx, conf.mlx_win, conf.map.img, 0, 0);
	mlx_key_hook(conf.mlx_win, key_hook, &conf);
	mlx_loop(conf.mlx);
}

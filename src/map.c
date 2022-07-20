/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:23 by gmachado          #+#    #+#             */
/*   Updated: 2022/07/20 00:41:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*resize_buffer(char *buf, int cur_size, int increment)
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

char	**get_map_file_contents(int fd)
{
	ssize_t	num_read;
	char	read_str[BUFFER_SIZE + 1];
	char	*buf;
	char	*temp;
	char	**split_buf;

	num_read = 1;
	buf = (char *)malloc(sizeof(char));
	buf[0] = '\0';
	while (num_read)
	{
		if (buf == NULL)
			return (NULL);
		num_read = read(fd, read_str, BUFFER_SIZE);
		if (num_read <= 0)
			break ;
		read_str[num_read] = '\0';
		temp = buf;
		buf = ft_strjoin(buf, read_str);
		free(temp);
	}
	split_buf = ft_split(buf, '\n');
	free(buf);
	return (split_buf);
}

int	load_map(t_config *conf, char *map_file)
{
	int	fd;

	if (ft_strncmp(map_file + ft_strlen(map_file) - 4, ".ber", 4))
		return (1);
	fd = open(map_file, O_RDONLY);
	if (fd < 3)
		return (1);
	conf->map = get_map_file_contents(fd);
	if (validate_map(conf))
		return (1);
	close(fd);
	return (0);
}

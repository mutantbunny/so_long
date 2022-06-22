/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:08:23 by gmachado          #+#    #+#             */
/*   Updated: 2022/06/22 05:22:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

char	*resize_buffer(char *buf, size_t cur_size, size_t increment)
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
	int		start;
	int		cur_size;
	char	*buf;
	char	**split_buf;

	num_read = 1;
	start = 0;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (num_read)
	{
		if (buf == NULL)
			return (NULL);
		num_read = read(fd, buf + start, BUFFER_SIZE);
		if (num_read < 0)
			return (NULL);
		buf[num_read] = '\0';
		if (num_read == BUFFER_SIZE)
			buf = resize_buffer(buf, start + BUFFER_SIZE + 1, BUFFER_SIZE);
		start += num_read;
	}
	split_buf = ft_split(buf, '\n');
	free(buf);
	return (split_buf);
}

int	load_map(t_config *conf, char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 3)
		return (1);
	conf->map = get_map_file_contents(fd);
	if (!validate_map(conf))
		return (1);
	close(fd);
	return (0);
}

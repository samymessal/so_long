/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:42:07 by smessal           #+#    #+#             */
/*   Updated: 2022/09/17 16:52:52 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (0);
	count = 1;
	while (count)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (count - 1);
		count++;
		free(line);
	}
	close(fd);
	return (0);
}

char	**read_map(char *file_name)
{
	int		lines;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	lines = ft_count_lines(file_name);
	map = ft_calloc(sizeof(char *), (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 1024)
		return (free(map), NULL);
	while (i < lines)
		map[i++] = get_next_line(fd);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:42:07 by smessal           #+#    #+#             */
/*   Updated: 2022/09/15 20:05:49 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_lines(char	*file_name)
{
	int		lines;
	int		fd;
	int		ret;
	char	*temp;
	char	temp2;

	ret = 1;
	lines = 1;
	fd = open(file_name, O_RDONLY);
	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (0);
	temp2 = 'c';
	while (ret == 1)
	{
		ret = read(fd, temp, 1);
		if (ret != 1)
		{
			if (temp2 == '\n')
				return (0);
		}
		temp2 = temp[0];
		if (temp[0] == '\n')
			lines++;
	}
	return (free(temp), lines);
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
	while (i < lines)
		map[i++] = get_next_line(fd);
	return (map);
}

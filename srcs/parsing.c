/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:42:07 by smessal           #+#    #+#             */
/*   Updated: 2022/09/02 18:51:41 by smessal          ###   ########.fr       */
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

	ret = BUFFER_SIZE;
	lines = 1;
	fd = open(file_name, O_RDONLY);
	temp = malloc(sizeof(char) * 2);
	if (!temp)
		return (0);
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret != BUFFER_SIZE)
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
	map = malloc(sizeof(char *) * lines);
	if (!map)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	while (i < lines)
		map[i++] = get_next_line(fd);
	return (map);
}

int	square_map(char **map)
{
	int	line1;
	int	i;
	int	j;

	i = 0;
	while (map[0][i] && map[0][i] != '\0' && map[0][i] != '\n')
		i++;
	line1 = i;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\0' && map[i][j] != '\n')
			j++;
		if (j != line1)
			return (0);
		i++;
	}
	return (1);
}

int	errors_man(char **av, char **map, int lines)
{
	if (!ft_ber_file(av))
		return (0);
	else if (!square_map(map))
		return (0);
	else if (!map_walls(map, lines))
		return (0);
	else if (!map_elements(map))
		return (0);
}

int	main(int ac, char **av)
{
	char	*test;
	int		lines;
	char	**all;
	int		fd;
	
	if (ac > 2)
		return (0);
	lines = ft_count_lines(av[1]);
	all = read_map(av[1]);
	if (!errors_man(av, all, lines))
		printf("Error\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:13 by smessal           #+#    #+#             */
/*   Updated: 2022/09/17 16:53:15 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_flooded(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y][x - 1] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y + 1][x] == '0' || map[y][x + 1] == 'C')
					return (0);
				if (map[y - 1][x] == '0' || map[y][x + 1] == 'C')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	fill(char **map, int y, int x)
{
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C')
		map[y][x + 1] = 'P';
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C')
		map[y][x - 1] = 'P';
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C')
		map[y + 1][x] = 'P';
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C')
		map[y - 1][x] = 'P';
}

void	flood(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				fill(map, y, x);
			x++;
		}
		y++;
	}
}

int	valid_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (map[i][j + 1] == 'P')
					return (1);
				if (map[i][j - 1] == 'P')
					return (1);
				if (map[i + 1][j] == 'P')
					return (1);
				if (map[i - 1][j] == 'P')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(char **map, int lines)
{
	int		i;
	char	**map_cpy;

	i = -1;
	map_cpy = ft_calloc(sizeof(char *), lines + 1);
	if (!map_cpy)
		return (0);
	while (++i < lines)
		map_cpy[i] = ft_strdup(map[i]);
	while (!is_flooded(map_cpy))
		flood(map_cpy);
	if (valid_path(map_cpy) && !count_elements(map_cpy, 'C'))
		return (free_tab(map_cpy), 1);
	return (free_tab(map_cpy), 0);
}

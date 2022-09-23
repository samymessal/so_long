/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:33:37 by smessal           #+#    #+#             */
/*   Updated: 2022/09/22 17:34:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_ber_file(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
		{
			if (ft_strncmp(&av[1][i], ".ber", 5))
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	map_walls(char **map, char *filename)
{
	int	i;
	int	j;
	int	lines;

	i = 0;
	j = 0;
	lines = ft_count_lines(filename);
	while (map[0][i] != '\0' && map[0][i] != '\n')
	{
		if (map[0][i] != '1')
			return (0);
		if (map[lines - 1][i++] != '1')
			return (0);
	}
	while (map[j])
	{
		if (map[j][i - 1] != '1')
			return (0);
		if (map[j++][0] != '1')
			return (0);
	}
	return (1);
}

int	count_elements(char **map, char elem)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == elem)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_elements(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	items;
	int	start;

	i = 0;
	exit = count_elements(map, 'E');
	items = count_elements(map, 'C');
	start = count_elements(map, 'P');
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	if (exit != 1 || items < 1 || start != 1)
		return (0);
	return (1);
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

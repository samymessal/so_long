/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:53:25 by smessal           #+#    #+#             */
/*   Updated: 2022/09/09 17:50:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_pos	find_elem(char **map, char elem)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.height = 0;
	pos.width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == elem)
			{
				pos.width = j;
				pos.height = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	pos.height = -1;
	return (pos);
}

int	check_if_ok(char **map, t_pos pos_p, int keysym, char elem)
{
	if (keysym == 'w')
	{
		if (map[pos_p.height - 1][pos_p.width] != elem)
			return (1);
	}
	else if (keysym == 'a')
	{
		if (map[pos_p.height][pos_p.width - 1] != elem)
			return (1);
	}
	else if (keysym == 's')
	{
		if (map[pos_p.height + 1][pos_p.width] != elem)
			return (1);
	}
	else if (keysym == 'd')
	{
		if (map[pos_p.height][pos_p.width + 1] != elem)
			return (1);
	}
	return (0);
}

void	move(char **map, t_pos pos_p, int keysym)
{
	if (!check_if_ok(map, pos_p, keysym, '1') || !check_if_ok(map, pos_p, keysym, 'E'))
		return ;
	if (keysym == 'w')
	{
		map[pos_p.height][pos_p.width] = '0';
		map[pos_p.height - 1][pos_p.width] = 'P';
	}
	else if (keysym == 'a')
	{
		map[pos_p.height][pos_p.width] = '0';
		map[pos_p.height][pos_p.width - 1] = 'P';
	}
	else if (keysym == 's')
	{
		map[pos_p.height][pos_p.width] = '0';
		map[pos_p.height + 1][pos_p.width] = 'P';
	}
	else if (keysym == 'd')
	{
		map[pos_p.height][pos_p.width] = '0';
		map[pos_p.height][pos_p.width + 1] = 'P';
	}
}

void	update_map(char **map)
{
	t_pos	exit;
	
	(void)exit;
	if (find_elem(map, 'C').height == -1)
	{
		exit = find_elem(map, 'E');
		if (exit.height == -1)
			return ;
		map[exit.height][exit.width] = 'O'; 
	}
	return ;
}
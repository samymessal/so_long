/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:27:28 by smessal           #+#    #+#             */
/*   Updated: 2022/09/17 16:07:13 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	messages(char **av, char **map)
{
	if (!ft_ber_file(av))
	{
		write(1, "Error\nOnly map format accepted is .ber\n", 39);
		return (0);
	}
	else if (!square_map(map))
	{
		write(1, "Error\nMap is not rectangular\n", 29);
		return (0);
	}
	else if (!map_walls(map, av[1]))
	{
		write(1, "Error\nMap not closed, can't swim all the atlantic\n", 50);
		return (0);
	}
	else if (!map_elements(map))
	{
		write(1, "Error\nMap's element count is incorrect\n", 39);
		return (0);
	}
	return (1);
}

int	messages2(char **av, char **map)
{
	if (!flood_fill(map, ft_count_lines(av[1])))
	{
		write(1, "Error\nThe consulate is closed, no visas available\n", 50);
		return (0);
	}
	return (1);
}

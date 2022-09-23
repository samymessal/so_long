/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:27:28 by smessal           #+#    #+#             */
/*   Updated: 2022/09/23 12:39:40 by smessal          ###   ########.fr       */
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
		write(1, "Error\nMap not closed, you'll get lost before ", 45);
		write(1, "reaching Algeciras\n", 20);
		return (0);
	}
	else if (!map_elements(map))
	{
		write(1, "Error\nInvalid Map\n", 18);
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

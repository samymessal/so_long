/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:27:28 by smessal           #+#    #+#             */
/*   Updated: 2022/09/11 21:02:06 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	messages(char **av, char **map)
{
	if (!ft_ber_file(av))
	{
		write(1, "Error\nOnly map format accepted is .ber\n", 40);
		return (0);
	}
	else if (!square_map(map))
	{
		write(1, "Error\nMap is not rectangular\n", 30);
		return (0);
	}
	else if (!map_walls(map, av[1]))
	{
		write(1, "Error\nMap not closed, can't swim all the atlantic\n", 51);
		return (0);
	}
	else if (!map_elements(map))
	{
		write(1, "Error\nToo many start positions\n", 32);
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:20:55 by smessal           #+#    #+#             */
/*   Updated: 2022/09/11 16:51:34 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char **map;
	
	if (ac != 2)
		return (0);
	map = read_map(av[1]);
	// if (!map)
	// {
	// 	write(1, "Error\nFailed map allocation", 28);
	// 	return (0);
	// }
	// if (!messages(av, map))
	// 	return (0);
	init_win(av[1], map);
	return (0);
}

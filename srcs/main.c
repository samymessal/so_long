/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:20:55 by smessal           #+#    #+#             */
/*   Updated: 2022/09/17 17:05:29 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac != 2)
	{
		write(1, "Error\nToo many arguments\n", 25);
		return (0);
	}
	map = read_map(av[1]);
	if (!map || !map[0])
	{
		write(1, "Error\nFailed map allocation\n", 28);
		if (map)
			free(map);
		return (0);
	}
	if (!messages(av, map) || !(messages2(av, map)))
		return (free_tab(map), 0);
	if (!init_win(av[1], map))
		return (0);
	return (0);
}

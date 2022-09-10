/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:09:18 by smessal           #+#    #+#             */
/*   Updated: 2022/09/10 18:18:38 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	t_pos	player;
	t_pos	exit;
	int		count_police;
	
	if (find_elem(data->map, 'E').height == -1)
		exit = find_elem(data->map, 'O');
	else
		exit = find_elem(data->map, 'E');
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	player = find_elem(data->map, 'P');
	count_police = count_elements(data->map, 'M');
	move(data->map, player, keysym);
	if (check_if_ok(data->map, player, keysym, '1') &&
		check_if_ok(data->map, player, keysym, 'E'))
		data->moves++;
	/* CHANGE TO FT_PRINT */
	printf("Moves: %d\n", data->moves);
	update_map(data->map);
	player = find_elem(data->map, 'P');
	if ((player.height == exit.height && player.width == exit.width) ||
		count_elements(data->map, 'M') != count_police)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	handle_no_event(void *data)
{
	t_data	*test;
	
	test = data;
	return (0);
}
int	handle_keyrelease(int keysym, void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	t_data	*test;
	(void)keysym;
	test = data;
	return (0);
}

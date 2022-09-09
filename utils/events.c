/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:09:18 by smessal           #+#    #+#             */
/*   Updated: 2022/09/09 17:52:25 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	t_pos	player;
	t_pos	exit;
	
	if (find_elem(data->map, 'E').height == -1)
		exit = find_elem(data->map, 'O');
	else
		exit = find_elem(data->map, 'E');
	if (keysym == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	player = find_elem(data->map, 'P');
	move(data->map, player, keysym);
	update_map(data->map);
	player = find_elem(data->map, 'P');
	if (player.height == exit.height && player.width == exit.width)
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

	printf("Keyrelease: %d\n", keysym);
	test = data;
	return (0);
}

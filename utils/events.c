/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:09:18 by smessal           #+#    #+#             */
/*   Updated: 2022/09/04 18:10:22 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
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

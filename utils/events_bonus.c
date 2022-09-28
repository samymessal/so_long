/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:36:33 by smessal           #+#    #+#             */
/*   Updated: 2022/09/28 22:50:21 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_data *data, int keysym)
{
	t_pos	player;

	player = find_elem(data->map, 'P');
	move(data->map, player, keysym);
	if (check_if_ok(data->map, player, keysym, '1')
		&& check_if_ok(data->map, player, keysym, 'E'))
	{
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		write (1, "\n", 1);
	}
	update_map(data->map);
}

void	game_over(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		write(1, "Well, I guess I'm staying with Baba & Mama\n", 43);
	}
	if (keysym == -200)
	{
		mlx_loop_end(data->mlx_ptr);
		write(1, "Game over\nNext time bring money for the bribe", 45);
		write(1, ", f*****g amateur\n", 19);
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	t_pos	player;
	t_pos	exit;
	int		count_police;

	exit = find_elem(data->map, 'E');
	if (exit.height == -1)
		exit = find_elem(data->map, 'O');
	game_over(keysym, data);
	count_police = count_elements(data->map, 'M');
	move_player(data, keysym);
	if (count_police != count_elements(data->map, 'M'))
		game_over(-200, data);
	player = find_elem(data->map, 'P');
	if (player.height == exit.height && player.width == exit.width)
	{
		mlx_loop_end(data->mlx_ptr);
		write(1, "First step done, now you need to get married\n", 45);
	}
	return (0);
}

int	mouse_click(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	write(1, "Well, I guess I'm staying with Baba & Mama\n", 43);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:27:08 by smessal           #+#    #+#             */
/*   Updated: 2022/09/15 19:37:01 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*init_img(t_data *data)
{
	t_img	*all;

	all = ft_calloc(sizeof(t_img), 8);
	if (!all)
		return (0);
	if(!download_image(data, &all[0], "img/case_0.xpm"))
		return (NULL);
	if(!download_image(data, &all[1], "img/fence.xpm"))
		return (NULL);
	if (!download_image(data, &all[2], "img/douane.xpm"))
		return (NULL);
	if (!download_image(data, &all[3], "img/passport.xpm"))
		return (NULL);
	if (!download_image(data, &all[4], "img/player.xpm"))
		return (NULL);
	if (!download_image(data, &all[5], "img/police.xpm"))
		return (NULL);
	if (!download_image(data, &all[6], "img/boat.xpm"))
		return (NULL);
	return (all);
}

void	draw_all(t_img *img_big, t_img *all, char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.height = 0;
	while (map[i])
	{
		j = 0;
		pos.width = 0;
		while (map[i][j] && map[i][j] != '\0' && map[i][j] != '\n')
		{
			conditions_draw(img_big, all, map[i][j], pos);
			pos.width += 64;
			j++;
		}
		i++;
		pos.height += 64;
	}
}

int	render(t_all *all)
{
	draw_all(&all->big, all->imgs, all->data.map);
	mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, \
		all->big.mlx_img, 0, 0);
	return (0);
}

int	init_data(t_data *data, int width, int height, char **map)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "SO_LONG");
	if (!data->win_ptr)
		return (free(data->win_ptr), 0);
	data->map = map;
	data->moves = 0;
	return (1);
}

int	init_win(char *filename, char **map)
{
	t_data	data;
	t_pos	screen;
	t_img	*imgs;
	t_all	all;

	screen.width = (ft_strlen(map[0]) - 1) * 64;
	screen.height = (ft_count_lines(filename)) * 64;
	if(!init_data(&data, screen.width, screen.height, map))
		return (free_tab(map), 0);
	all.data = data;
	all.big.mlx_img = mlx_new_image(data.mlx_ptr, screen.width, screen.height);
	all.big.addr = mlx_get_data_addr(all.big.mlx_img, &all.big.bpp, \
						&all.big.line_len, &all.big.endian);
	imgs = init_img(&data);
	if (!imgs)
		return (free_all(all), 0);
	all.imgs = imgs;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, \
		&handle_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &all);
	mlx_loop(data.mlx_ptr);
	free_all(all);
	return (1);
}

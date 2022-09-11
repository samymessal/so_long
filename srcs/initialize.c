/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:27:08 by smessal           #+#    #+#             */
/*   Updated: 2022/09/11 16:25:43 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*init_img(t_data *data)
{
	t_img	*all;
	int		i;

	i = 0;
	all = ft_calloc(sizeof(t_img), 8);
	if (!all)
		return (0);
	download_image(data, &all[0], "img/case_0.xpm");
	download_image(data, &all[1], "img/fence.xpm");
	download_image(data, &all[2], "img/douane.xpm");
	download_image(data, &all[3], "img/passport.xpm");
	download_image(data, &all[4], "img/player.xpm");
	download_image(data, &all[5], "img/police.xpm");
	download_image(data, &all[6], "img/boat.xpm");
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

void	init_data(t_data *data, int width, int height, char **map)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "SO_LONG");
	data->map = map;
	data->moves = 0;
}

void	init_win(char *filename, char **map)
{
	t_data	data;
	t_pos	screen;
	t_img	*imgs;
	t_all	all;

	screen.width = (ft_strlen(map[0]) - 1) * 64;
	screen.height = (ft_count_lines(filename)) * 64;
	init_data(&data, screen.width, screen.height, map);
	all.data = data;
	all.big.mlx_img = mlx_new_image(data.mlx_ptr, screen.width, screen.height);
	all.big.addr = mlx_get_data_addr(all.big.mlx_img, &all.big.bpp, \
						&all.big.line_len, &all.big.endian);
	imgs = init_img(&data);
	all.imgs = imgs;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, \
		&handle_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &all);
	mlx_loop(data.mlx_ptr);
	free_all(all);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:27:08 by smessal           #+#    #+#             */
/*   Updated: 2022/09/09 17:32:22 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	*init_img(t_data *data)
{
	t_img	*all;
	int		i;
	
	i = 0;
	all = malloc(sizeof(t_img) * 7);
	if (!all)
		return (0);
	download_image(data, &all[0], "img/case_0.xpm");
	download_image(data, &all[1], "img/fence.xpm");
	download_image(data, &all[2], "img/douane.xpm");
	download_image(data, &all[3], "img/passport.xpm");
	download_image(data, &all[4], "img/player.xpm");
	download_image(data, &all[5], "img/dog.xpm");
	download_image(data, &all[6], "img/boat.xpm");
	return (all);
}

void	draw_all(t_img *img_big, t_img *all, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] == '0')
				draw(img_big, all[0], x, y);
			else if (map[i][j] == '1')
				draw(img_big, all[1], x, y);
			else if (map[i][j] == 'C')
				draw(img_big, all[3], x, y);
			else if (map[i][j] == 'P')
				draw(img_big, all[4], x, y);
			else if (map[i][j] == 'E')
				draw(img_big, all[5], x, y);
			else if (map[i][j] == 'O')
				draw(img_big, all[6], x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}

int	render(t_all *all)
{
	draw_all(&all->big, all->imgs, all->data.map);
	mlx_put_image_to_window(all->data.mlx_ptr, all->data.win_ptr, all->big.mlx_img, 0, 0);
	return (0);
}

void	init_win(char *filename)
{
	char	**map;
	t_data	data;
	t_pos	screen;
	t_img	*imgs;
	t_img	big;
	t_all	all;
	
	map = read_map(filename);
	// if (!map || !errors_man(av, map, ft_count_lines(filename)))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (0);
	// }
	screen.width = (ft_strlen(map[0]) - 1) * 64;
	screen.height = (ft_count_lines(filename)) * 64;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, screen.width, screen.height, "SO_LONG");
	data.map = map;
	big.mlx_img = mlx_new_image(data.mlx_ptr, screen.width, screen.height);
	big.addr = mlx_get_data_addr(big.mlx_img, &big.bpp, &big.line_len, &big.endian);
	imgs = init_img(&data);
	all.data = data;
	all.big = big;
	all.imgs = imgs;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &all);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
